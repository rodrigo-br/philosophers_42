/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 11:52:55 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	sleep_n_think(t_infos *inf)
{
	pthread_mutex_lock(&forks()->lock_print);
	if (!forks()->dead)
		printf("%lld %lld is sleeping\n", time_now() - forks()->start, inf->id);
	pthread_mutex_unlock(&forks()->lock_print);
	usleep(inf->time_to_sleep);
	pthread_mutex_lock(&forks()->lock_print);
	if (!forks()->dead)
		printf("%lld %lld is thinking\n", time_now() - forks()->start, inf->id);
	pthread_mutex_unlock(&forks()->lock_print);
}

static void	eat(t_infos *inf)
{
	pthread_mutex_lock(&forks()->lock_print);
	look_for_forks(inf);
	if (!forks()->dead)
		printf("%lld %lld is eating\n", (time_now() - forks()->start), inf->id);
	inf->starving = time_now();
	if (!(--inf->iterations))
		forks()->iterations--;
	pthread_mutex_unlock(&forks()->lock_print);
}

static t_ulli	ft_atolli(const char *n)
{
	t_ulli	result;
	int		i;

	result = 0;
	i = 0;
	while (n[i] <= '9' && n[i] >= '0')
		result = result * 10 + (n[i++] - '0');
	return (result);
}

void	*live(void *_infos)
{
	t_infos		*infos;

	infos = (t_infos *)_infos;
	if (!(infos->id % 2))
		usleep(100);
	while (!forks()->dead)
	{
		lock_forks(infos);
		eat(infos);
		usleep(infos->time_to_eat);
		make_forks_true(infos);
		unlock_forks(infos);
		sleep_n_think(infos);
	}
	return ((void *)&infos->id);
}

void	create_philosopher(char **argv)
{
	t_infos			*infos;
	t_ulli			i;
	t_ulli			size;

	size = ft_atolli(argv[0]);
	summon_forks(size);
	i = -1;
	while (++i < size)
	{
		pthread_mutex_init(&forks()->lock_forks[i], NULL);
		forks()->forks[i] = TRUE;
	}
	infos = malloc(sizeof(t_infos) * (size));
	init_infos(argv, infos, size);
	forks()->socrates = malloc(sizeof(pthread_t) * infos->n_of_philos);
	forks()->start = time_now();
	i = -1;
	while (++i < infos->n_of_philos)
	{
		infos[i].starving = forks()->start;
		pthread_create(&forks()->socrates[i], NULL, &live, &infos[i]);
	}
	the_sixth_sense(infos);
}

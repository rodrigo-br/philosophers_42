/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 15:05:53 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	sleep_n_think(t_infos *inf)
{
	pthread_mutex_lock(&inf->forks->lock_print);
	if (!inf->forks->dead)
		printf("%lu %d is sleeping\n", time_now() - inf->forks->start, inf->id);
	pthread_mutex_unlock(&inf->forks->lock_print);
	usleep(inf->time_to_sleep);
	pthread_mutex_lock(&inf->forks->lock_print);
	if (!inf->forks->dead)
		printf("%lu %d is thinking\n", time_now() - inf->forks->start, inf->id);
	pthread_mutex_unlock(&inf->forks->lock_print);
}

static void	eat(t_infos *inf)
{
	pthread_mutex_lock(&inf->forks->lock_print);
	look_for_forks(inf);
	if (!inf->forks->dead)
	{
		inf->starving = time_now();
		printf("%lu %d is eating\n", (time_now() - inf->forks->start), inf->id);
	}
	if (!(--inf->iterations))
		inf->forks->iterations--;
	pthread_mutex_unlock(&inf->forks->lock_print);
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
	while (!infos->forks->dead)
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
	t_infos		*infos;
	t_philos	*philos;
	pthread_t	*socrates;
	int			i;
	int			size;

	size = ft_atolli(argv[0]);
	i = -1;
	infos = (t_infos *)malloc(sizeof(t_infos));
	init_infos(argv, infos);
	philos = malloc(sizeof(t_philos) * (size));
	start_a_very_boring_friendship(infos, philos);
	while (++i < size)
	{
		pthread_mutex_init(&forks->lock_forks[i], NULL);
		forks->forks[i] = TRUE;
	}
	socrates = malloc(sizeof(pthread_t) * infos->n_of_philos);
	forks->start = time_now();
	i = -1;
	while (++i < infos->n_of_philos)
	{
		infos[i].starving = forks->start;
		pthread_create(&forks->socrates[i], NULL, &live, &infos[i]);
	}
	the_sixth_sense(infos);
	free(forks);
}

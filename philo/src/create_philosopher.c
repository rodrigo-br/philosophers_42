/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/09 19:14:40 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

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
	long int	now;
	t_infos		*infos;

	infos = (t_infos *)_infos;
	if (!(infos->id % 2))
		usleep(10);
	now = 0;
	while (!forks()->dead)
	{
		lock_forks(infos);
		pthread_mutex_lock(&forks()->lock_print);
		now = get_time_now() - forks()->start;
		printf("%ld %lld is eating\n", now, infos->id);
		pthread_mutex_unlock(&forks()->lock_print);
		infos->starving = get_time_now();
		if (!(--infos->iterations))
			forks()->iterations--;
		usleep(infos->time_to_eat);
		unlock_forks(infos);
		pthread_mutex_lock(&forks()->lock_print);
		now = get_time_now() - forks()->start;
		printf("%ld %lld is sleeping\n", now, infos->id);
		pthread_mutex_unlock(&forks()->lock_print);
		usleep(infos->time_to_sleep);
		pthread_mutex_lock(&forks()->lock_print);
		now = get_time_now() - forks()->start;
		printf("%ld %lld is thinking\n", now, infos->id);
		pthread_mutex_unlock(&forks()->lock_print);	
	}
	return ((void *)&infos->id);
}

void	create_philosopher(char **argv)
{
	t_infos			*infos;
	t_ulli			i;
	t_ulli			size;

	i = -1;
	forks()->dead = FALSE;
	forks()->start = 0;
	pthread_mutex_init(&forks()->lock_death, NULL);
	size = ft_atolli(argv[0]);
	forks()->forks = malloc(size * sizeof(int));
	forks()->lock_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * size);
	while (++i < size)
	{
		pthread_mutex_init(&forks()->lock_forks[i], NULL);
		forks()->forks[i] = TRUE;
	}
	i = -1;
	infos = malloc(sizeof(t_infos) * (size));
	init_infos(argv, infos, size);
	forks()->socrates = malloc(sizeof(pthread_t) * infos->n_of_philos);
	forks()->start = get_time_now();
	while (++i < infos->n_of_philos)
	{
		infos[i].starving = forks()->start;
		pthread_create(&forks()->socrates[i], NULL, &live, &infos[i]);
	}
	the_sixth_sense(infos);
}

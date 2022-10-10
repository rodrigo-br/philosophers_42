/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 17:46:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	sleep_n_think(t_philos *ph)
{
	pthread_mutex_lock(&ph->lock_print);
	if (!ph->infos->dead && ph->infos->iterations)
		printf("%lu %d is sleeping\n", \
		time_now() - ph->infos->start, ph->id);
	pthread_mutex_unlock(&ph->lock_print);
	usleep(ph->infos->time_to_sleep);
	pthread_mutex_lock(&ph->lock_print);
	if (!ph->infos->dead && ph->infos->iterations)
		printf("%lu %d is thinking\n", \
		time_now() - ph->infos->start, ph->id);
	pthread_mutex_unlock(&ph->lock_print);
}

static void	eat(t_philos *ph)
{
	pthread_mutex_lock(&ph->lock_print);
	if (!ph->infos->dead)
	{
		ph->starving = time_now();
		printf("%lu %d is eating\n", \
		(time_now() - ph->infos->start), ph->id);
	}
	if (!(--ph->meals))
		ph->infos->iterations--;
	if (!ph->infos->iterations)
		ph->infos->dead = TRUE;
	pthread_mutex_unlock(&ph->lock_print);
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

void	*live(void *_philos)
{
	t_philos	*philos;

	philos = (t_philos *)_philos;
	if (!(philos->id % 2))
		usleep(100);
	while (!philos->infos->dead)
	{
		lock_forks(philos);
		eat(philos);
		usleep(philos->infos->time_to_eat);
		unlock_forks(philos);
		sleep_n_think(philos);
	}
	return ((void *)&philos->id);
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
	socrates = malloc(sizeof(pthread_t) * infos->n_of_philos);
	i = -1;
	infos->start = time_now();
	while (++i < infos->n_of_philos)
	{
		philos[i].starving = infos->start;
		pthread_create(&socrates[i], NULL, &live, &philos[i]);
	}
	the_sixth_sense(philos, socrates);
}

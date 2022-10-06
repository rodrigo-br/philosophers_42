/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 19:51:58 by ralves-b         ###   ########.fr       */
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
	long int	start;
	long int	now;
	t_infos		*infos;

	start = get_time_now();
	infos = (t_infos *)_infos;
	infos->starving = start;
	now = 0;
	while (1)
	{
		while (1)
		{
			if (check_death(infos->starving, infos, start, 0))
				return (NULL);
			pthread_mutex_lock(&forks()->lock_forks);
			if (look_for_forks(infos))
			{
				pthread_mutex_unlock(&forks()->lock_forks);
				break ;
			}
			pthread_mutex_unlock(&forks()->lock_forks);
		}
		now = get_time_now() - start;
		printf("%ld %lld is eating\n", now, infos->id);
		infos->starving = get_time_now();
		if (check_death(infos->starving, infos, start, infos->time_to_eat / 1000))
			return (NULL);
		usleep(infos->time_to_eat);
		pthread_mutex_lock(&forks()->lock_forks);
		make_forks_true(infos);
		pthread_mutex_unlock(&forks()->lock_forks);
		now = get_time_now() - start;
		printf("%ld %lld is sleeping\n", now, infos->id);
		if (check_death(infos->starving, infos, start, infos->time_to_sleep / 1000))
			return (NULL);
		usleep(infos->time_to_sleep);
		now = get_time_now() - start;
		printf("%ld %lld is thinking\n", now, infos->id);		
	}
	return (NULL);
}

void	create_philosopher(char **argv)
{
	t_infos			*infos;
	pthread_t		*socrates;
	t_ulli			i;
	t_ulli			size;

	i = -1;
	pthread_mutex_init(&forks()->lock_forks, NULL);
	size = ft_atolli(argv[0]);
	forks()->forks = malloc(size * sizeof(int));
	while (++i < size)
		forks()->forks[i] = TRUE;
	i = 0;
	infos = malloc(sizeof(t_infos) * (size));
	init_infos(argv, infos, size);
	socrates = malloc(sizeof(pthread_t) * infos->n_of_philos);
	while (i < infos->n_of_philos)
	{
		pthread_create(&socrates[i], NULL, &live, &infos[i]);
		i++;
	}
	i = 0;
	while (i < infos->n_of_philos)
	{
		pthread_join(socrates[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&forks()->lock_forks);
}

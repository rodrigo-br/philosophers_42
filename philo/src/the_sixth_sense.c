/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sixth_sense.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:56:12 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 17:05:53 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	make_it_die(t_philos philos)
{
	pthread_mutex_lock(&philos.lock_death);
	pthread_mutex_lock(&philos.lock_print);
	printf("%lu %d died\n", (time_now() - philos.infos->start), philos.id);
	philos.dead = TRUE;
	pthread_mutex_unlock(&philos.lock_death);
	pthread_mutex_unlock(&philos.lock_print);
}

void	end_it_all(t_philos *philos, pthread_t *socrates)
{
	int	i;
	int	counter;

	i = -1;
	counter = philos->infos->n_of_philos;
	while (++i < counter)
	{
		pthread_mutex_destroy(&philos->forks[i]);
	}
	pthread_mutex_destroy(&philos->lock_print);
	pthread_mutex_destroy(&philos->lock_death);
	free(philos->forks);
	free(philos->forks);
	free(socrates);
}

void	the_sixth_sense(t_philos *philos, pthread_t *socrates)
{
	int				i;
	unsigned long	dead_end;

	i = 0;
	dead_end = philos->infos->time_to_die / 1000;
	philos->meals = philos->infos->iterations;
	usleep(dead_end * 0.9);
	while (!philos->dead)
	{
		if (!philos->infos->iterations)
			philos->dead = TRUE;
		if ((time_now() - philos[i].starving) > dead_end)
		{
			make_it_die(philos[i]);
		}
		i = (i + 1) % philos->infos->n_of_philos;
	}
	end_it_all(philos, socrates);
}

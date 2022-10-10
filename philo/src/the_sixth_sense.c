/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sixth_sense.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:56:12 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 17:44:26 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	make_it_die(t_philos *philos, int i)
{
	pthread_mutex_lock(&philos->lock_death);
	pthread_mutex_lock(&philos->lock_print);
	printf("%lu %d died\n", (time_now() - philos[i].infos->start), philos[i].id);
	philos->infos->dead = 1;
	pthread_mutex_unlock(&philos->lock_death);
	pthread_mutex_unlock(&philos->lock_print);
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
	free(socrates);
}

void	the_sixth_sense(t_philos *philos, pthread_t *socrates)
{
	int				i;
	unsigned long	dead_end;

	i = 0;
	dead_end = philos->infos->time_to_die / 1000;
	usleep(dead_end * 0.9);
	while (!philos->infos->dead)
	{
		if (!philos->infos->iterations)
		{
			philos->infos->dead = TRUE;
			pthread_mutex_lock(&philos->lock_print);
			end_it_all(philos, socrates);
			return ;
		}
		if ((time_now() - philos[i].starving) > dead_end)
		{
			philos->infos->dead = TRUE;
			make_it_die(philos, i);
			return ;
		}
		i = (i + 1) % philos->infos->n_of_philos;
	}
}

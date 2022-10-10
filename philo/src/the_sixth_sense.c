/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sixth_sense.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:56:12 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 16:06:23 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	make_it_die(t_infos infos)
{
	pthread_mutex_lock(&infos.forks->lock_death);
	pthread_mutex_lock(&infos.forks->lock_print);
	printf("%lu %d died\n", (time_now() - infos.forks->start), infos.id);
	infos.forks->dead = TRUE;
	pthread_mutex_unlock(&infos.forks->lock_death);
	pthread_mutex_unlock(&infos.forks->lock_print);
}

void	end_it_all(t_infos	*infos)
{
	int	i;
	int	counter;

	i = -1;
	counter = infos[0].n_of_philos;
	while (++i < counter)
	{
		pthread_mutex_destroy(&infos->forks->lock_forks[i]);
		pthread_join(infos->forks->socrates[i], NULL);
	}
	pthread_mutex_destroy(&infos->forks->lock_print);
	pthread_mutex_destroy(&infos->forks->lock_death);
	free(infos->forks->forks);
	free(infos->forks->lock_forks);
	free(infos->forks->socrates);
	free(infos);
}

void	the_sixth_sense(void *_infos)
{
	t_infos			*infos;
	int				iterations;
	int				i;
	unsigned long	dead_end;

	i = 0;
	iterations = -1;
	infos = (t_infos *)_infos;
	dead_end = infos[0].time_to_die / 1000;
	if (infos->iterations_on)
		iterations = infos->n_of_philos;
	infos->forks->iterations = iterations;
	usleep((infos[0].time_to_die * 0.9) / 1000);
	while (!infos->forks->dead)
	{
		if (!infos->forks->iterations)
			infos->forks->dead = TRUE;
		if ((time_now() - infos[i].starving) > dead_end)
		{
			make_it_die(infos[i]);
		}
		i = (i + 1) % infos->n_of_philos;
	}
	end_it_all(infos);
}

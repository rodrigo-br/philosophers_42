/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sixth_sense.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:56:12 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 12:10:24 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	make_it_die(t_infos infos)
{
	pthread_mutex_lock(&forks()->lock_death);
	pthread_mutex_lock(&forks()->lock_print);
	printf("%lld %lld died\n", (time_now() - forks()->start), infos.id);
	forks()->dead = TRUE;
	pthread_mutex_unlock(&forks()->lock_death);
	pthread_mutex_unlock(&forks()->lock_print);
}

void	end_it_all(t_infos	*infos)
{
	int	i;
	int	counter;

	i = -1;
	counter = infos[0].n_of_philos;
	while (++i < counter)
	{
		pthread_mutex_destroy(&forks()->lock_forks[i]);
		pthread_join(forks()->socrates[i], NULL);
	}
	pthread_mutex_destroy(&forks()->lock_print);
	pthread_mutex_destroy(&forks()->lock_death);
	free(forks()->forks);
	free(forks()->lock_forks);
	free(forks()->socrates);
	free(infos);
}

void	the_sixth_sense(void *_infos)
{
	t_infos		*infos;
	int			iterations;
	int			i;
	t_ulli		dead_end;

	i = 0;
	iterations = -1;
	infos = (t_infos *)_infos;
	dead_end = infos[0].time_to_die / 1000;
	if (infos->iterations_on)
		iterations = infos->n_of_philos;
	forks()->iterations = iterations;
	usleep((infos[0].time_to_die * 0.9) / 1000);
	while (!forks()->dead)
	{
		if (!forks()->iterations)
			forks()->dead = TRUE;
		if ((time_now() - infos[i].starving) > dead_end)
		{
			make_it_die(infos[i]);
		}
		i = (i + 1) % infos->n_of_philos;
	}
	end_it_all(infos);
}

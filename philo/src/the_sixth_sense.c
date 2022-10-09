/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sixth_sense.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:56:12 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/09 12:54:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void *the_sixth_sense(void *_infos)
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
	while (TRUE)
	{
		if (!forks()->iterations)
			exit(printf("Geral comeu ;D\n"));
		if ((get_time_now() - infos[i].starving) > dead_end)
		{
			pthread_mutex_lock(&forks()->lock_death);
			pthread_mutex_lock(&forks()->lock_print);
			printf("%lld %lld died\n", (get_time_now() - forks()->start), infos[i].id);
			forks()->dead = infos[i].id;
			usleep(666);
			exit(0);
		}
		i = (i + 1) % infos->n_of_philos;
	}
	return (NULL);
}

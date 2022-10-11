/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knock_knock_neo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:24:54 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/12 00:08:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	knock_knock_neo(t_philos *neb_crew, int action)
{
	pthread_mutex_lock(neb_crew->infos->lock_print);
	if (action == PILLS_TAKEN && ignorance_is_a_bliss(neb_crew->infos))
		printf("%d %ld has taken the fork\n", \
		neb_crew->id, time_now() - neb_crew->infos->start);
	else if (action == EAT && ignorance_is_a_bliss(neb_crew->infos))
	{
		neb_crew->starving = time_now() - neb_crew->infos->start;
		neb_crew->meals--;
		printf("%d %ld is eating\n", neb_crew->id, \
		time_now() - neb_crew->infos->start);
	}
	else if (action == SLEEP && ignorance_is_a_bliss(neb_crew->infos))
		printf("%d %ld is sleeping\n", neb_crew->id, \
		time_now() - neb_crew->infos->start);
	else if (action == THINK && ignorance_is_a_bliss(neb_crew->infos))
		printf("%d %ld is thinking\n", neb_crew->id, \
		time_now() - neb_crew->infos->start);
	else if (action == PLOT_TWIST)
	{
		if (neb_crew->meals != 0)
			printf("%d %ld is dead\n", neb_crew->id, \
			time_now() - neb_crew->infos->start);
		else
			neb_crew->infos->dead = FALSE;
	}
	pthread_mutex_unlock(neb_crew->infos->lock_print);
}

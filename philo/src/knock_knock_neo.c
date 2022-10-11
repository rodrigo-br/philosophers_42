/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knock_knock_neo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:24:54 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 19:51:38 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	knock_knock_neo(t_philos *nb, int action)
{
	pthread_mutex_lock(nb->infos->lock_print);
	if (action == PILLS_TAKEN && ignorance_is_a_bliss(nb->infos))
		printf("%d %ld has taken the fork\n", \
		nb->id, time_now() - nb->infos->start);
	else if (action == EAT && ignorance_is_a_bliss(nb->infos))
	{
		nb->starving = time_now() - nb->infos->start;
		nb->meals--;
		printf("%d %ld is eating\n", nb->id, \
		time_now() - nb->infos->start);
	}
	else if (action == SLEEP && ignorance_is_a_bliss(nb->infos))
		printf("%d %ld is sleeping\n", nb->id, \
		time_now() - nb->infos->start);
	else if (action == THINK && ignorance_is_a_bliss(nb->infos))
		printf("%d %ld is thinking\n", nb->id, \
		time_now() - nb->infos->start);
	else if (action == PLOT_TWIST)
	{
		if (nb->meals != 0)
			printf("%d %ld is dead\n", nb->id, time_now() - nb->infos->start);
		else
			nb->infos->dead = FALSE;
	}
	pthread_mutex_unlock(nb->infos->lock_print);
}

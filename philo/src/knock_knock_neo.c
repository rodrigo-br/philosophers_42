/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knock_knock_neo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:24:54 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/12 18:32:22 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	knock_knock_neo(t_philos *nb, int action)
{
	t_ul	now;

	pthread_mutex_lock(nb->infos->lock_print);
	now = time_now() - nb->infos->start;
	if (action == PILLS_TAKEN && ignorance_is_a_bliss(nb->infos))
		printf("%ld %d has taken the fork\n", now, nb->id);
	else if (action == EAT && ignorance_is_a_bliss(nb->infos))
		printf("%ld %d is eating\n", now, nb->id);
	else if (action == SLEEP && ignorance_is_a_bliss(nb->infos))
		printf("%ld %d is sleeping\n", now, nb->id);
	else if (action == THINK && ignorance_is_a_bliss(nb->infos))
		printf("%ld %d is thinking\n", now, nb->id);
	else if (action == PLOT_TWIST)
		printf("%ld %d is dead\n", now, nb->id);
	pthread_mutex_unlock(nb->infos->lock_print);
}

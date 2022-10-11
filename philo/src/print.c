/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:24:54 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 14:39:06 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	knock_knock_neo(t_philos *philos, int action)
{
	pthread_mutex_lock(philos->infos->lock_print);
	if (action == PILLS_TAKEN && ignorance_is_a_bliss(philos->infos))
		printf("%d %ld has taken the fork\n", philos->id, time_now() - philos->infos->start);
	else if (action == EAT && ignorance_is_a_bliss(philos->infos))
		printf("%d %ld is eating\n", philos->id, time_now() - philos->infos->start);
	else if (action == SLEEP && ignorance_is_a_bliss(philos->infos))
		printf("%d %ld is sleeping\n", philos->id, time_now() - philos->infos->start);
	else if (action == THINK && ignorance_is_a_bliss(philos->infos))
		printf("%d %ld is thinking\n", philos->id, time_now() - philos->infos->start);
	pthread_mutex_unlock(philos->infos->lock_print);
}

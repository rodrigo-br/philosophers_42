/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:24:54 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 14:03:57 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	print(t_philos *philos, int action)
{
	pthread_mutex_lock(philos->infos->lock_print);
	if (action == PILLS_TAKEN)
		printf("%d %ld has taken the fork\n", philos->id, time_now() - philos->infos->start);
	else if (action == EAT)
		printf("%d %ld is eating\n", philos->id, time_now() - philos->infos->start);
	else if (action == SLEEP)
		printf("%d %ld is sleeping\n", philos->id, time_now() - philos->infos->start);
	else if (action == THINK)
		printf("%d %ld is thinking\n", philos->id, time_now() - philos->infos->start);
	pthread_mutex_unlock(philos->infos->lock_print);
}

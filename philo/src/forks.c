/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:45:13 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 17:22:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	unlock_forks(t_philos *philos)
{
	if (philos->infos->n_of_philos == 1)
		return ;
	pthread_mutex_unlock(&philos->forks[right(philos)]);
	pthread_mutex_unlock(&philos->forks[left(philos)]);
}

void	lock_forks(t_philos *philos)
{
	if (philos->infos->n_of_philos != 1 && philos->infos->iterations)
	{
		pthread_mutex_lock(&philos->forks[left(philos)]);
		printf("%lu %d has taken the fork\n", \
		(time_now() - philos->infos->start), philos->id);
		pthread_mutex_lock(&philos->forks[right(philos)]);
		printf("%lu %d has taken the fork\n", \
		(time_now() - philos->infos->start), philos->id);
		return ;
	}
	printf("%lu %d has taken the fork\n", \
	(time_now() - philos->infos->start), philos->id);
	while (!philos->dead)
		;
}

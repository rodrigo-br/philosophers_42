/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_important_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:47:19 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/12 16:53:56 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

short int	lock_this(t_philos	*neb_crew)
{
	int	miaw;

	pthread_mutex_lock(neb_crew->lock_starving);
	miaw = neb_crew->starving;
	pthread_mutex_unlock(neb_crew->lock_starving);
	return (miaw);
}

short int	idk_a_good_name(t_philos *neb_crew)
{
	pthread_mutex_lock(neb_crew->lock_meals);
	neb_crew->meals--;
	if (!(neb_crew->meals))
	{
		neb_crew->infos->must_eat--;
		return (pthread_mutex_unlock(neb_crew->lock_meals), TRUE);
	}
	pthread_mutex_unlock(neb_crew->lock_meals);
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_important_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:47:19 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/13 15:55:55 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_ul	lock_this(t_philos	*neb_crew)
{
	t_ul	starving;

	pthread_mutex_lock(neb_crew->lock_starving);
	starving = neb_crew->starving;
	pthread_mutex_unlock(neb_crew->lock_starving);
	return (starving);
}

short int	handle_meals(t_philos *neb_crew)
{
	pthread_mutex_lock(neb_crew->lock_meals);
	neb_crew->meals--;
	if (!(neb_crew->meals))
	{
		neb_crew->infos->must_eat--;
		pthread_mutex_unlock(neb_crew->lock_meals);
		return (TRUE);
	}
	pthread_mutex_unlock(neb_crew->lock_meals);
	return (FALSE);
}

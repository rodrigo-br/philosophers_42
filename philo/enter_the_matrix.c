/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_the_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:37:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 14:14:11 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	choose_the_pills(t_philos *philos)
{
	if (!(philos->id % 2))
	{
		pthread_mutex_lock(philos->blue);
		print(philos, PILLS_TAKEN);
		pthread_mutex_lock(philos->red);
		print(philos, PILLS_TAKEN);
	}
	else
	{
		pthread_mutex_lock(philos->red);
		print(philos, PILLS_TAKEN);
		pthread_mutex_lock(philos->blue);
		print(philos, PILLS_TAKEN);
	}
	print(philos, EAT);
	philos->starving = time_now() - philos->infos->start;
	usleep(philos->infos->time_to_eat * 1000);
	pthread_mutex_unlock(philos->blue);
	pthread_mutex_unlock(philos->red);
	philos->meals--;
	
}

void	*crew_do_your_thing(void *_philos)
{
	t_philos	*philos;

	philos = (t_philos *)_philos;
	if (!(philos->id % 2))
		usleep(10);
	while (TRUE)
	{
		choose_the_pills(philos);
		if (!philos->meals)
			return (EXCHANGE_YOUR_FRIENDS_FOR_A_HAMBURGUER);
		print(philos, SLEEP);
		usleep(philos->infos->time_to_sleep * 1000);
		print(philos, THINK);
	}
	return (NULL);
}

void	pick_up_the_phone(t_philos *neb_crew, t_infos *infos)
{
	pthread_t	*crew;
	int			i;

	crew = (pthread_t *)malloc(sizeof(pthread_t) * infos->n_of_philos);
	infos->start = time_now();
	i = -1;
	while (++i < infos->n_of_philos)
		pthread_create(&crew[i], NULL, &crew_do_your_thing, &neb_crew[i]);
	i = -1;
	while (++i < infos->n_of_philos)
		pthread_join(crew[i], NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_the_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:37:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 15:36:52 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*do_the_oracle_thing(void *_neb_crew)
{
	t_philos	**neb_crew;
	t_infos		*infos;
	int			i;

	i = 0;
	neb_crew = (t_philos **)_neb_crew;
	infos = (*neb_crew)->infos;
	while (infos->must_eat)
	{
		if (time_now() - infos->start - (*neb_crew)[i].starving > (t_ul)infos->time_to_die)
		{
			pthread_mutex_lock(infos->lock_end);
			infos->dead = TRUE;
			pthread_mutex_unlock(infos->lock_end);
			knock_knock_neo(&(*neb_crew)[i], PLOT_TWIST);
			return (OH_NO_NEO_COULDN_T_ESCAPE_THE_BULLETS);
		}
		i = (i + 1) % infos->n_of_philos;
	}
	return (NEO_SAVED_THE_DAY_YAAAAAY);
}

int	ignorance_is_a_bliss(t_infos *infos)
{
	pthread_mutex_lock(infos->lock_end);
	if (infos->dead)
	{
		pthread_mutex_unlock(infos->lock_end);
		return (0);
	}
	pthread_mutex_unlock(infos->lock_end);
	return (1);
}

void	choose_the_pills(t_philos *philos)
{
	if (!(philos->id % 2))
	{
		pthread_mutex_lock(philos->blue);
		knock_knock_neo(philos, PILLS_TAKEN);
		pthread_mutex_lock(philos->red);
		knock_knock_neo(philos, PILLS_TAKEN);
	}
	else
	{
		pthread_mutex_lock(philos->red);
		knock_knock_neo(philos, PILLS_TAKEN);
		pthread_mutex_lock(philos->blue);
		knock_knock_neo(philos, PILLS_TAKEN);
	}
	knock_knock_neo(philos, EAT);
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
	while (ignorance_is_a_bliss(philos->infos))
	{
		choose_the_pills(philos);
		if (!philos->meals)
		{
			philos->infos->must_eat--;
			return (EXCHANGE_YOUR_FRIENDS_FOR_A_HAMBURGUER);
		}
		knock_knock_neo(philos, SLEEP);
		usleep(philos->infos->time_to_sleep * 1000);
		knock_knock_neo(philos, THINK);
	}
	return (EXCHANGE_YOUR_FRIENDS_FOR_A_HAMBURGUER);
}

void	pick_up_the_phone(t_philos *neb_crew, t_infos *infos)
{
	pthread_t	*crew;
	pthread_t	*the_oracle;
	int			i;

	crew = (pthread_t *)malloc(sizeof(pthread_t) * infos->n_of_philos);
	the_oracle = (pthread_t *)malloc(sizeof(pthread_t));
	infos->must_eat = infos->n_of_philos;
	infos->start = time_now();
	i = -1;
	while (++i < infos->n_of_philos)
		pthread_create(&crew[i], NULL, &crew_do_your_thing, &neb_crew[i]);
	pthread_create(the_oracle, NULL, &do_the_oracle_thing, &neb_crew);
	i = -1;
	while (++i < infos->n_of_philos)
		pthread_join(crew[i], NULL);
	pthread_join(*the_oracle, NULL);
}

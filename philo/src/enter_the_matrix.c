/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_the_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:37:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/12 16:58:57 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ignorance_is_a_bliss(t_infos *infos)
{
	int	ignorance;

	pthread_mutex_lock(infos->lock_end);
	ignorance = TRUE;
	if (infos->end)
	{
		ignorance = FALSE;
	}
	pthread_mutex_unlock(infos->lock_end);
	return (ignorance);
}

void	choose_the_pills(t_philos *neb_crew)
{
	pthread_mutex_lock(neb_crew->blue);
	pthread_mutex_lock(neb_crew->red);
	if (!ignorance_is_a_bliss(neb_crew->infos))
	{
		pthread_mutex_unlock(neb_crew->blue);
		pthread_mutex_unlock(neb_crew->red);
		return ;
	}
	knock_knock_neo(neb_crew, PILLS_TAKEN);
	knock_knock_neo(neb_crew, PILLS_TAKEN);
	knock_knock_neo(neb_crew, EAT);
	pthread_mutex_lock(neb_crew->lock_starving);
	neb_crew->starving = time_now() - neb_crew->infos->start;
	pthread_mutex_unlock(neb_crew->lock_starving);
	usleep((neb_crew->infos->time_to_eat * 1000));
	pthread_mutex_unlock(neb_crew->blue);
	pthread_mutex_unlock(neb_crew->red);
}

void	*do_the_oracle_thing(void *_neb_crew)
{
	t_philos	*neb_crew;
	t_infos		*infos;
	t_ul		now;
	int			i;

	i = 0;
	neb_crew = (t_philos *)_neb_crew;
	infos = neb_crew->infos;
	while (infos->must_eat)
	{
		now = time_now() - infos->start;
		if (now - lock_this(&neb_crew[i]) > (t_ul)infos->time_to_die)
		{
			pthread_mutex_lock(infos->lock_end);
			infos->end = TRUE;
			pthread_mutex_unlock(infos->lock_end);
			return (knock_knock_neo(&neb_crew[i], PLOT_TWIST), MR_SMITH_WIN);
		}
		usleep(5);
		i = (i + 1) % infos->n_of_philos;
	}
	return (NEO_SAVED_THE_DAY_YAAAAAY);
}

void	*crew_do_your_thing(void *_neb_crew)
{
	t_philos	*neb_crew;

	neb_crew = (t_philos *)_neb_crew;
	if (neb_crew->id % 2)
		usleep(69);
	if (neb_crew->infos->n_of_philos == 1)
	{
		knock_knock_neo(neb_crew, PILLS_TAKEN);
		return (usleep(neb_crew->infos->time_to_die * 1000), WRONG_PILL);
	}
	while (ignorance_is_a_bliss(neb_crew->infos))
	{
		choose_the_pills(neb_crew);
		if (idk_a_good_name(neb_crew))
			return (SAVE_THE_DAY);
		knock_knock_neo(neb_crew, SLEEP);
		usleep(neb_crew->infos->time_to_sleep * 1000);
		knock_knock_neo(neb_crew, THINK);
		usleep(500);
	}
	return (SAVE_THE_DAY);
}

void	pick_up_the_phone(t_philos *neb_crew, t_infos *infos)
{
	pthread_t	*crew;
	pthread_t	*the_oracle;
	int			i;
	int			n;

	n = infos->n_of_philos;
	crew = (pthread_t *)malloc(sizeof(pthread_t) * n);
	the_oracle = (pthread_t *)malloc(sizeof(pthread_t));
	infos->must_eat = n;
	infos->start = time_now();
	i = -1;
	while (++i < n)
		pthread_create(&crew[i], NULL, &crew_do_your_thing, &neb_crew[i]);
	pthread_create(the_oracle, NULL, &do_the_oracle_thing, neb_crew);
	i = -1;
	while (++i < n)
		pthread_join(crew[i], NULL);
	pthread_join(*the_oracle, NULL);
	the_end(neb_crew, infos, crew, the_oracle);
}

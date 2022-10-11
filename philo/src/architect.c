/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   architect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:10:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 12:36:21 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	init_infos(char **argv, t_infos *infos)
{
	t_mutex	*print;

	infos->n_of_philos = ft_atoi(argv[0]);
	infos->time_to_die = ft_atoi(argv[1]);
	infos->time_to_eat = ft_atoi(argv[2]);
	infos->time_to_sleep = ft_atoi(argv[3]);
	infos->dead = 0;
	infos->must_eat = -1;
	infos->start = 0;
	if (argv[4])
		infos->must_eat = ft_atoi(argv[4]);
	print = (t_mutex *)malloc(sizeof(t_mutex));
	infos->lock_print = print;
	pthread_mutex_init(infos->lock_print, NULL);
}

void	init_pills(t_mutex **pills, int n_of_philos)
{
	int	i;

	*pills = (t_mutex *)malloc(sizeof(t_mutex) * n_of_philos);
	i = -1;
	while (++i < n_of_philos)
		pthread_mutex_init(&((*pills)[i]), NULL);
}

void	init_crew(t_infos *infos, t_mutex **pills, t_philos **neb_crew)
{
	int	i;

	*neb_crew = (t_philos *)malloc(sizeof(t_philos) * infos->n_of_philos);
	i = -1;	
	while (++i < infos->n_of_philos)
	{
		(*neb_crew)[i].id = i + 1;
		(*neb_crew)[i].blue = &(*pills)[i];
		(*neb_crew)[i].red = &(*pills)[(*neb_crew)[i].id % infos->n_of_philos];
		(*neb_crew)[i].meals = infos->must_eat;
		(*neb_crew)[i].infos = infos;
		(*neb_crew)[i].starving = 0;
	}
}

void	architect_do_your_thing(char **argv, t_infos *infos, t_mutex **pills, \
	t_philos **neb_crew)
{
	init_infos(argv, infos);
	init_pills(pills, infos->n_of_philos);
	init_crew(infos, pills, neb_crew);
}

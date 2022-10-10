/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 17:36:41 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	right(t_philos *philos)
{
	return (philos->id % philos->infos->n_of_philos);
}

int	left(t_philos *philos)
{
	return (philos->id - 1);
}

void	start_a_very_boring_friendship(t_infos *infos, t_philos *philos)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	print;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * infos->n_of_philos);
	while (++i < infos->n_of_philos)
		pthread_mutex_init(&forks[i], NULL);
	pthread_mutex_init(&death, NULL);
	pthread_mutex_init(&print, NULL);
	i = -1;
	while (++i < infos->n_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].forks = forks;
		philos[i].lock_death = death;
		philos[i].lock_print = print;
		philos[i].meals = infos->iterations;
		philos[i].infos = infos;
		philos[i].starving = 0;
	}
	infos->iterations = infos->n_of_philos;
}

int	main(int argc, char **argv)
{
	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	create_philosopher(argv);
	return (EXIT_SUCCESS);
}

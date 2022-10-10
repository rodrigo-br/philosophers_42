/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 15:08:30 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	right(t_infos *infos)
{
	return (infos->id % infos->n_of_philos);
}

int	left(t_infos *infos)
{
	return (infos->id - 1);
}

	// int				id;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	lock_death;
	// pthread_mutex_t	lock_print;
	// int				dead;
	// int				meals;
	// t_infos			infos;
	// unsigned long	starving;
void	start_a_very_boring_friendship(t_infos *infos, t_philos *philos)
{
	
}

int	main(int argc, char **argv)
{
	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	create_philosopher(argv);
	return (EXIT_SUCCESS);
}

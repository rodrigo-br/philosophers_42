/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 10:16:35 by ralves-b         ###   ########.fr       */
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
	
}

int	main(int argc, char **argv)
{
	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	create_philosopher(argv);
	return (EXIT_SUCCESS);
}

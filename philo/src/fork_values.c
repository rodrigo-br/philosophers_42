/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:57:12 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 16:16:49 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	fork_values(t_infos **info)
{
	t_ulli	i;

	i = 0;
	(*info)->table.forks[0][LEFT] = TRUE;
	if ((*info)->n_of_philos == 1)
		return ;
	(*info)->table.forks[0][RIGHT] = TRUE;
	while (++i < (*info)->n_of_philos)
	{
		(*info)->table.forks[i][RIGHT] = (*info)->table.forks[i - 1][LEFT];
		(*info)->table.forks[i][RIGHT] = TRUE;
	}
	i--;
	(*info)->table.forks[i][RIGHT] = (*info)->table.forks[i - 1][LEFT];
	(*info)->table.forks[i][LEFT] = (*info)->table.forks[0][RIGHT];
}

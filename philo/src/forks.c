/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:45:13 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 19:45:26 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_forks	*forks(void)
{
	static t_forks	fork;

	return (&fork);
}

int	look_for_forks(t_infos *infos)
{
	if (infos->n_of_philos == 1)
		return (0);
	if (infos->id == infos->n_of_philos
		&& forks()->forks[infos->id - 1] && forks()->forks[0])
	{
		forks()->forks[infos->id - 1] = FALSE;
		forks()->forks[0] = FALSE;
		return (1);
	}
	else if (infos->id < infos->n_of_philos
		&& forks()->forks[infos->id] && forks()->forks[infos->id - 1])
	{
		forks()->forks[infos->id] = FALSE;
		forks()->forks[infos->id - 1] = FALSE;
		return (1);
	}
	return (0);
}

void	make_forks_true(t_infos *infos)
{
	if (infos->id == infos->n_of_philos)
	{
		forks()->forks[infos->id - 1] = TRUE;
		forks()->forks[0] = TRUE;
		return ;
	}
	forks()->forks[infos->id] = TRUE;
	forks()->forks[infos->id - 1] = TRUE;
}

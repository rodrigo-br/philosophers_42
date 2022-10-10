/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:45:13 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 16:06:18 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	unlock_forks(t_infos *infos)
{
	if (infos->n_of_philos == 1)
		return ;
	pthread_mutex_unlock(&infos->forks->lock_forks[right(infos)]);
	pthread_mutex_unlock(&infos->forks->lock_forks[left(infos)]);
}

void	lock_forks(t_infos *infos)
{
	if (infos->n_of_philos != 1)
	{
		pthread_mutex_lock(&infos->forks->lock_forks[left(infos)]);
		pthread_mutex_lock(&infos->forks->lock_forks[right(infos)]);
		return ;
	}
	printf("%lu %d has taken the fork\n", \
	(time_now() - infos->forks->start), infos->id);
	while (!infos->forks->dead)
		;
}

void	look_for_forks(t_infos *infos)
{
	if (infos->n_of_philos == 1)
		return ;
	if (!infos->id % 2)
	{
		if (infos->forks->forks[left(infos)] && infos->forks->forks[right(infos)]
			&& infos->forks->iterations && !infos->forks->dead)
		{
			infos->forks->forks[left(infos)] = FALSE;
			printf("%lu %d has taken the fork\n", \
			(time_now() - infos->forks->start), infos->id);
			infos->forks->forks[right(infos)] = FALSE;
			printf("%lu %d has taken the fork\n", \
			(time_now() - infos->forks->start), infos->id);
		}
	}
	else if (infos->forks->forks[right(infos)] && infos->forks->forks[left(infos)]
		&& infos->forks->iterations && !infos->forks->dead)
	{
		infos->forks->forks[right(infos)] = FALSE;
		printf("%lu %d has taken the fork\n", \
		(time_now() - infos->forks->start), infos->id);
		infos->forks->forks[left(infos)] = FALSE;
		printf("%lu %d has taken the fork\n", \
		(time_now() - infos->forks->start), infos->id);
	}
}

void	make_forks_true(t_infos *infos)
{
	infos->forks->forks[left(infos)] = TRUE;
	infos->forks->forks[right(infos)] = TRUE;
}

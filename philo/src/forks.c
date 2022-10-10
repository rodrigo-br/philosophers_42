/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:45:13 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 11:06:45 by ralves-b         ###   ########.fr       */
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

void	unlock_forks(t_infos *infos)
{
	if (infos->n_of_philos == 1)
		return ;
	pthread_mutex_unlock(&forks()->lock_forks[right(infos)]);
	pthread_mutex_unlock(&forks()->lock_forks[left(infos)]);
}

void	lock_forks(t_infos *infos)
{
	if (infos->n_of_philos == 1)
	{
		printf("%lld %lld has taken the fork\n", (get_time_now() - forks()->start), infos->id);
		while (!forks()->dead)
			;
	}
	pthread_mutex_lock(&forks()->lock_forks[left(infos)]);
	pthread_mutex_lock(&forks()->lock_forks[right(infos)]);
}

t_forks	*forks(void)
{
	static t_forks	fork;

	return (&fork);
}

int	look_for_forks(t_infos *infos)
{
	if (infos->n_of_philos == 1)
		return (0);
	if (!infos->id % 2)
	{
		if (forks()->forks[left(infos)] && forks()->forks[right(infos)] && forks()->iterations && !forks()->dead)
		{
			forks()->forks[left(infos)] = FALSE;
			printf("%lld %lld has taken the fork\n", (get_time_now() - forks()->start), infos->id);
			forks()->forks[right(infos)] = FALSE;
			printf("%lld %lld has taken the fork\n", (get_time_now() - forks()->start), infos->id);
			return (1);
		}
	}
	else
	{
		if (forks()->forks[right(infos)] && forks()->forks[left(infos)] && forks()->iterations && !forks()->dead)
		{
			forks()->forks[right(infos)] = FALSE;
			printf("%lld %lld has taken the fork\n", (get_time_now() - forks()->start), infos->id);
			forks()->forks[left(infos)] = FALSE;
			printf("%lld %lld has taken the fork\n", (get_time_now() - forks()->start), infos->id);
			return (1);
		}
	}
	return (0);
}

void	make_forks_true(t_infos *infos)
{
	forks()->forks[left(infos)] = TRUE;
	forks()->forks[right(infos)] = TRUE;
}

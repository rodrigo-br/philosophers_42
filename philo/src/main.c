/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 12:04:36 by ralves-b         ###   ########.fr       */
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

t_forks	*forks(void)
{
	static t_forks	fork;

	return (&fork);
}

void	summon_forks(t_ulli size)
{
	forks()->dead = FALSE;
	forks()->start = 0;
	pthread_mutex_init(&forks()->lock_death, NULL);
	pthread_mutex_init(&forks()->lock_print, NULL);
	forks()->forks = malloc(size * sizeof(int));
	forks()->lock_forks = malloc(sizeof(pthread_mutex_t) * size);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	create_philosopher(argv);
	return (EXIT_SUCCESS);
}

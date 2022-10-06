/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 15:30:23 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*live(void *_infos)
{
	long int	start;
	long int	now;
	long int	starving;
	t_infos		*infos;

	start = get_time_now();
	starving = start;
	infos = (t_infos *)_infos;
	now = 0;
	while (1)
	{
		while (1)
		{
			if (check_death(starving, infos, start, 0))
				return (NULL);
			if (infos->table.forks[0][LEFT] && infos->table.forks[0][RIGHT])
			{
				infos->table.forks[0][LEFT] = FALSE;
				infos->table.forks[0][RIGHT] = FALSE;
				break ;
			}
		}
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ COMÊNO\n", now);
		starving = get_time_now();
		if (check_death(starving, infos, start, infos->time_to_eat / 1000))
			return (NULL);
		usleep(infos->time_to_eat);
		infos->table.forks[0][LEFT] = TRUE;
		infos->table.forks[0][RIGHT] = TRUE;
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ DURMINU\n", now);
		if (check_death(starving, infos, start, infos->time_to_sleep / 1000))
			return (NULL);
		usleep(infos->time_to_sleep);
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ PENSANDO\n", now);		
	}
	return (NULL);
}

void	create_philosopher(char **argv)
{
	t_infos		infos;
	pthread_t	*socrates;
	t_ulli		i;

	i = 0;
	init_infos(argv, &infos);
	socrates = malloc(sizeof(pthread_t) * infos.n_of_philos);
	while (i < infos.n_of_philos)
	{
		pthread_create(&socrates[i], NULL, &live, &infos);
		i++;
	}
	i = 0;
	while (i < infos.n_of_philos)
	{
		pthread_join(socrates[i], NULL);
		i++;
	}
}

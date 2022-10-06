/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 08:21:51 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>



void	*live(void *infos)
{
	long int	start;
	long int	now;
	long int	starving;

	printf("SOCRATES DOIDÃO MENÓ\n");
	start = get_time_now();
	starving = start;
	now = 0;
	while (1)
	{
		while (1)
		{
			if (check_death(starving, ((t_infos *)infos)))
				return (NULL);
			if (((t_infos *)infos)->table.forks)
			{
				((t_infos *)infos)->table.forks = FALSE;
				break ;
			}
		}
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ COMÊNO\n", now);
		starving = get_time_now();
		usleep(((t_infos *)infos)->time_to_eat);
		((t_infos *)infos)->table.forks = TRUE;
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ DURMINU\n", now);
		usleep(((t_infos *)infos)->time_to_sleep);
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ PENSANDO\n", now);		
	}
	return (NULL);
}

void	create_philosopher(char **argv)
{
	t_infos		infos;
	pthread_t	socrates;
	//pthread_t	main;

	init_infos(argv, &infos);
	pthread_create(&socrates, NULL, &live, &infos);
	//pthread_create(&main, NULL, &live, &infos);
	pthread_join(socrates, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:43:53 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/05 21:14:25 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*live(void *voide)
{
	long int	start;
	long int	now;

	printf("SOCRATES DOIDÃO MENÓ\n");
	start = get_time_now();
	printf("0 - SOCRATES TÁ COMÊNU\n");
	while (1)
	{
		usleep(((t_infos *)voide)->time_to_eat);
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ DURMINU\n", now);
		usleep(((t_infos *)voide)->time_to_sleep);
		now = get_time_now() - start;
		printf("%ld - SOCRATES TÁ COMÊNO\n", now);
	}
	return (NULL);
}

void	create_philosopher(char **argv)
{
	t_infos	infos;
	pthread_t socrates;

	init_infos(argv, &infos);
	pthread_create(&socrates, NULL, live(&infos), NULL);
	pthread_join(socrates, NULL);
}

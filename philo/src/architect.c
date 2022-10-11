/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   architect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:10:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 11:46:39 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	ft_atoi(const char *n)
{
	int	result;
	int		i;

	result = 0;
	i = 0;
	while (n[i] <= '9' && n[i] >= '0')
		result = result * 10 + (n[i++] - '0');
	return (result);
}

void	init_infos(char **argv, t_infos *infos)
{
	t_mutex	*print;

	infos->n_of_philos = ft_atoi(argv[0]);
	infos->time_to_die = ft_atoi(argv[1]);
	infos->time_to_eat = ft_atoi(argv[2]);
	infos->time_to_sleep = ft_atoi(argv[3]);
	infos->dead = 0;
	infos->must_eat = -1;
	infos->start = 0;
	if (argv[4])
		infos->must_eat = ft_atoi(argv[4]);
	print = (t_mutex *)malloc(sizeof(t_mutex));
	infos->lock_print = print;
	pthread_mutex_init(infos->lock_print, NULL);
}

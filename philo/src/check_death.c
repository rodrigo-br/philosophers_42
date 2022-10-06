/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:22:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 08:29:28 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	check_death(t_ulli strv, t_infos *infos)
{
	if (get_time_now() - strv < infos->time_to_die / 1000)
		return (0);
	usleep(get_time_now() - strv);
	printf("SOCRATES MORREU MENÓ\n");
	return (1);
}

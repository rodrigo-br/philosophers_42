/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:22:23 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 18:52:31 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	check_death(t_ulli strv, t_infos *infos, t_ulli start, t_ulli activity)
{
	if ((get_time_now() + activity) - strv < infos->time_to_die / 1000)
		return (0);
	usleep(infos->time_to_die - ((get_time_now() - strv) * 1000));
	printf("%lld %lld died\n", (get_time_now() - start), infos->id);
	return (1);
}

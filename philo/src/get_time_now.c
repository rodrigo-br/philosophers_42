/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_now.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:07:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/05 21:11:43 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_ulli	get_time_now(void)
{
	struct timeval	time;
	t_ulli			seconds;
	t_ulli			micro_seconds;
	t_ulli			mili_seconds;

	gettimeofday(&time, NULL);
	seconds = time.tv_sec;
	micro_seconds = time.tv_usec;
	mili_seconds = (seconds * 1000000 + micro_seconds) / 1000;
	return (mili_seconds);
}

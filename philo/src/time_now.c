/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_now.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:07:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 16:06:26 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

unsigned long	time_now(void)
{
	struct timeval	time;
	unsigned long	seconds;
	unsigned long	micro_seconds;
	unsigned long	mili_seconds;

	gettimeofday(&time, NULL);
	seconds = time.tv_sec;
	micro_seconds = time.tv_usec;
	mili_seconds = seconds * 1000 + micro_seconds / 1000;
	return (mili_seconds);
}

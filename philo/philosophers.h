/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/05 18:43:25 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define VERY_LARGE_N 999999999999999999

typedef unsigned long long int	t_ulli;

typedef enum e_phil
{
	DEAD,
	EAT,
	THINK,
	SLEEP
}	t_phil;

int		check_args(int argc, char **argv);
void	teste(char *teste);

#endif
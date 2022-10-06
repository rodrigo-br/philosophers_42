/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 11:09:46 by ralves-b         ###   ########.fr       */
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

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef unsigned long long int	t_ulli;

typedef struct s_table
{
	t_bool	forks;
}	t_table;

typedef struct s_phil
{
	t_bool	dead;
	t_bool	wait;
	t_bool	eat;
	t_bool	think;
	t_bool	sleep;
}	t_phil;

typedef struct s_infos
{
	t_ulli	n_of_philos;
	t_ulli	time_to_die;
	t_ulli	time_to_eat;
	t_ulli	time_to_sleep;
	t_ulli	iterations;
	t_bool	iterations_on;
	t_table	table;
}	t_infos;

int			check_args(int argc, char **argv);
void		init_infos(char **argv, t_infos *info);
int			check_death(t_ulli strv, t_infos *infos, t_ulli start, t_ulli activity);
void		create_philosopher(char **argv);
t_ulli		get_time_now(void);
void		teste(char *teste);

#endif
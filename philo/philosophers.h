/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 14:43:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define VERY_LARGE_N	999999999999999999
# define TRUE 1
# define FALSE 0

typedef unsigned long long int	t_ulli;

typedef struct s_philos
{
	int				id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_death;
	pthread_mutex_t	lock_print;
	int				dead;
	int				meals;
	t_infos			infos;
	unsigned long	starving;
}	t_philos;

typedef struct s_infos
{
	unsigned long	start;
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				iterations;
}	t_infos;

int				check_args(int argc, char **argv);
void			init_infos(char **argv, t_infos *inf, int n, t_forks *forks);
void			create_philosopher(char **argv);
void			look_for_forks(t_infos *infos);
void			make_forks_true(t_infos *infos);
int				right(t_infos *infos);
int				left(t_infos *infos);
void			the_sixth_sense(void *_infos);
void			unlock_forks(t_infos *infos);
void			lock_forks(t_infos *infos);
void			summon_forks(int size, t_forks *forks);
unsigned long	time_now(void);

#endif
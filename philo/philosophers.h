/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 17:02:47 by ralves-b         ###   ########.fr       */
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

typedef struct s_infos
{
	unsigned long	start;
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				iterations;
}	t_infos;

typedef struct s_philos
{
	int				id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_death;
	pthread_mutex_t	lock_print;
	int				dead;
	int				meals;
	t_infos			*infos;
	unsigned long	starving;
}	t_philos;

int				check_args(int argc, char **argv);
void			init_infos(char **argv, t_infos *inf);
void			create_philosopher(char **argv);
void			look_for_forks(t_philos *philos);
void			make_forks_true(t_philos *philos);
int				right(t_philos *philos);
int				left(t_philos *philos);
void			the_sixth_sense(t_philos *philos, pthread_t *socrates);
void			unlock_forks(t_philos *philos);
void			lock_forks(t_philos *philos);
void			start_a_very_boring_friendship(t_infos *infos, t_philos *philos);
unsigned long	time_now(void);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 16:06:34 by ralves-b         ###   ########.fr       */
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

typedef struct s_forks
{
	unsigned long	start;
	pthread_t		*socrates;
	pthread_t		i_see_dead_people;
	pthread_mutex_t	*lock_forks;
	pthread_mutex_t	lock_death;
	pthread_mutex_t	lock_print;
	int				*forks;
	int				dead;
	int				iterations;
}	t_forks;

typedef struct s_infos
{
	int				id;
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				iterations;
	int				iterations_on;
	unsigned long	starving;
	t_forks			*forks;
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
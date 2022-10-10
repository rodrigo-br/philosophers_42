/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 12:13:35 by ralves-b         ###   ########.fr       */
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

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef unsigned long long int	t_ulli;

typedef struct s_forks
{
	t_ulli			start;
	pthread_t		*socrates;
	pthread_t		i_see_dead_people;
	pthread_mutex_t	*lock_forks;
	pthread_mutex_t	lock_death;
	pthread_mutex_t	lock_print;
	int				*forks;
	t_bool			dead;
	int				iterations;
}	t_forks;

typedef struct s_infos
{
	t_ulli			id;
	t_ulli			n_of_philos;
	t_ulli			time_to_die;
	t_ulli			time_to_eat;
	t_ulli			time_to_sleep;
	int				iterations;
	t_bool			iterations_on;
	long int		starving;
}	t_infos;

int			check_args(int argc, char **argv);
void		init_infos(char **argv, t_infos *info, t_ulli size);
void		create_philosopher(char **argv);
void		look_for_forks(t_infos *infos);
void		make_forks_true(t_infos *infos);
int			right(t_infos *infos);
int			left(t_infos *infos);
void		the_sixth_sense(void *nothing_yet);
void		unlock_forks(t_infos *infos);
void		lock_forks(t_infos *infos);
void		summon_forks(t_ulli size);
t_ulli		time_now(void);
t_forks		*forks(void);

#endif
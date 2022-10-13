/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/13 15:56:01 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <please_dont_open_me.h>

typedef unsigned long long int	t_ulli;
typedef pthread_mutex_t			t_mutex;
typedef unsigned long			t_ul;

typedef struct s_infos
{
	t_ul		start;
	t_mutex		*lock_print;
	t_mutex		*lock_end;
	int			n_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			end;
}	t_infos;

typedef struct s_philos
{
	int			id;
	t_mutex		*blue;
	t_mutex		*red;
	t_ul		starving;
	t_mutex		*lock_starving;
	t_mutex		*lock_meals;
	int			meals;
	t_infos		*infos;
}	t_philos;

t_ul		time_now(void);
int			ft_atoi(const char *n);
short int	check_args(int argc, char **argv);
int			ignorance_is_a_bliss(t_infos *infos);
void		knock_knock_neo(t_philos *philos, int action);
void		pick_up_the_phone(t_philos *neb_new, t_infos *infos);
void		architect_do_your_thing(char **argv, t_infos *infos, \
	t_mutex **pills, t_philos **neb_crew);
void		the_end(t_philos *neb_crew, t_infos *infos, \
	pthread_t *crew, pthread_t *the_oracle);
t_ul		lock_this(t_philos	*neb_crew);
short int	handle_meals(t_philos *neb_crew);

#endif
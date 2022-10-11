/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:18:51 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 12:12:19 by ralves-b         ###   ########.fr       */
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
typedef pthread_mutex_t			t_mutex;
typedef unsigned long			t_ul;

typedef struct s_infos
{
	t_ul		start;
	t_mutex		*lock_print;
	int			n_of_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	int			dead;
}	t_infos;

typedef struct s_philos
{
	int			id;
	t_mutex		*blue;
	t_mutex		*red;
	int			meals;
	t_infos		*infos;
	t_ul		starving;
}	t_philos;

int		check_args(int argc, char **argv);
int		ft_atoi(const char *n);
t_ul	time_now(void);
void	architect_do_your_thing(char **argv, t_infos *infos, t_mutex **pills, \
	t_philos **neb_crew);

#endif
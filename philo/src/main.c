/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/12 18:19:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	the_end(t_philos *neb_crew, t_infos *infos, \
	pthread_t *crew, pthread_t *the_oracle)
{
	int	i;

	i = -1;
	while (++i < infos->n_of_philos)
		pthread_mutex_destroy(neb_crew[i].blue);
	pthread_mutex_destroy(infos->lock_print);
	pthread_mutex_destroy(infos->lock_end);
	free(infos->lock_print);
	free(infos->lock_end);
	free(crew);
	free(the_oracle);
	free(neb_crew);
}

int	main(int argc, char **argv)
{
	t_infos		infos;
	t_mutex		*pills;
	t_philos	*nebuchadnezzar_crew;

	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	architect_do_your_thing(argv, &infos, &pills, &nebuchadnezzar_crew);
	pick_up_the_phone(nebuchadnezzar_crew, &infos);
	free(pills);
	return (EXIT_SUCCESS);
}

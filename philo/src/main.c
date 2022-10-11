/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 12:11:34 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	t_infos		infos;
	t_mutex		*pills;
	t_philos	*Nebuchadnezzar_crew;

	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	architect_do_your_thing(argv, &infos, &pills, &Nebuchadnezzar_crew);
	return (EXIT_SUCCESS);
}

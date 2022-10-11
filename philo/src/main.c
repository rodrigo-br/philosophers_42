/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 12:41:01 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	t_infos		infos;
	t_mutex		*pills;
	t_philos	*nebuchadnezzar_crew;

	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	architect_do_your_thing(argv, &infos, &pills, &nebuchadnezzar_crew);
	pick_up_the_phone(nebuchadnezzar_crew, &infos);
	return (EXIT_SUCCESS);
}

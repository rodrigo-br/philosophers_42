/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:28:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/05 19:57:35 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	if (check_args(argc, ++argv))
		return (EXIT_FAILURE);
	create_philosopher(argv);
	dprintf(2, "SUCCESS\n");
	return (EXIT_SUCCESS);
}

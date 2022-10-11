/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:44:04 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/11 15:44:13 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_atoi(const char *n)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (n[i] <= '9' && n[i] >= '0')
		result = result * 10 + (n[i++] - '0');
	return (result);
}

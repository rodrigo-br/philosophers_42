/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:07:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/05 18:11:24 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

static int	ft_is_all_digit(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] <= '9' && s[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

static unsigned long long int	ft_atolli(const char *n)
{
	unsigned long long int	result;
	int						i;

	result = 0;
	i = 0;
	if (!ft_is_all_digit(n))
		return (0);
	while (n[i] <= '9' && n[i] >= '0')
	{
		result = result * 10 + (n[i] - '0');
		i++;
	}
	return (result);
}

static int	is_all_num(char **argv)
{
	int	i;

	i = 0;
	if (!ft_atolli(argv[0]))
		return (0);
	while (argv[i])
	{
		if (!ft_is_all_digit(argv[i]) || ft_strlen(argv[i]) > 20
			|| (ft_strlen(argv[i]) == 20 && ft_atolli(argv[i]) <= VERY_LARGE_N))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if ((argc != 5 && argc != 6) || !is_all_num(argv))
	{
		printf("incorrect args, check subject\n");
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:07:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/06 19:22:05 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static int	ft_is_all_digit(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] <= '9' && s[i] >= '0'))
		i++;
	if (s[i])
		return (0);
	return (1);
}

static t_ulli	ft_atolli(const char *n)
{
	t_ulli	result;
	int		i;

	result = 0;
	i = 0;
	if (!ft_is_all_digit(n))
		return (0);
	while (n[i] <= '9' && n[i] >= '0')
		result = result * 10 + (n[i++] - '0');
	return (result);
}

static int	is_all_num(char **argv)
{
	int	i;
	int	length;

	i = 0;
	while (argv[i])
	{
		length = 0;
		while (argv[i][length])
			length++;
		if (!ft_is_all_digit(argv[i]) || length > 20
			|| (length == 20 && ft_atolli(argv[i]) <= VERY_LARGE_N))
			return (0);
		i++;
	}
	return (1);
}

/* Resolvi multiplicar aqui por 1000 ao invés de no usleep porque aqui só
multiplica uma vez, mas se deixar lá no usleep, vai ficar efetuando a
operação várias vezes em loop */
void	init_infos(char **argv, t_infos *info, t_ulli size)
{
	int	i_size;

	i_size = -1;
	while (++i_size < (int)size)
	{
		info[i_size].id = i_size + 1;
		info[i_size].n_of_philos = ft_atolli(argv[0]);
		info[i_size].time_to_die = ft_atolli(argv[1]) * 1000;
		info[i_size].time_to_eat = ft_atolli(argv[2]) * 1000;
		info[i_size].time_to_sleep = ft_atolli(argv[3]) * 1000;
		if (argv[4])
		{
			info[i_size].iterations = ft_atolli(argv[4]) * 1000;
			info[i_size].iterations_on = TRUE;
		}
		else
			info[i_size].iterations_on = FALSE;
	}
}

int	check_args(int argc, char **argv)
{
	if ((argc != 5 && argc != 6) || !is_all_num(argv) || !ft_atolli(argv[0]))
		return (printf("incorrect args, check subject\n"));
	if (argc == 6 && ft_atolli(argv[4]) == 0)
		return (printf("n of times each philo must eat should be > 0\n"));
	return (0);
}

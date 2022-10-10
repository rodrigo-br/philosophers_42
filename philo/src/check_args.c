/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:07:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/10 15:22:50 by ralves-b         ###   ########.fr       */
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

void	init_infos(char **argv, t_infos *inf, int n, t_forks *forks)
{
	int	i_size;

	i_size = -1;
	while (++i_size < n)
	{
		inf[i_size].iterations = -1;
		inf[i_size].id = i_size + 1;
		inf[i_size].n_of_philos = ft_atolli(argv[0]);
		inf[i_size].time_to_die = ft_atolli(argv[1]) * 1000;
		inf[i_size].time_to_eat = ft_atolli(argv[2]) * 1000;
		inf[i_size].time_to_sleep = ft_atolli(argv[3]) * 1000;
		if (argv[4])
		{
			inf[i_size].iterations = ft_atolli(argv[4]);
			inf[i_size].iterations_on = TRUE;
		}
		else
			inf[i_size].iterations_on = FALSE;
		inf[i_size].forks = forks;
	}
}

int	check_args(int argc, char **argv)
{
	if ((argc != 5 && argc != 6) || !is_all_num(argv) || !ft_atolli(argv[0])
		|| !ft_atolli(argv[3]) || !ft_atolli(argv[2]) || !ft_atolli(argv[1]))
		return (printf("incorrect args, check subject\n"));
	if (argc == 6 && ft_atolli(argv[4]) == 0)
		return (printf("n of times each philo must eat should be > 0\n"));
	return (0);
}

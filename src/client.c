/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:29:10 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/25 12:22:41 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

/*
void	f(void)
{
	system("leaks -q client");
	// EN MAIN
	atexit(f);
}
*/

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		ft_print_error("Check args.\n\n\tUsage: ./client <PID> <MESSAGE>\n\n");
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			ft_print_error("PID only contains numbers.\n");
		i++;
	}
	if (!argv[2][0])
		ft_print_error("Invalid Message.\n");
}

int	ft_atob(int pid, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 8)
	{
		if (c & (0x01 << i))
			flag = kill(pid, SIGUSR1);
		else
			flag = kill(pid, SIGUSR2);
		if (flag == -1)
			return (flag);
		usleep(200);
		i++;
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*msg;
	int		flag;
	int		i;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	msg = ft_strjoin(argv[2], "\n");
	if (!msg)
		return (1);
	i = 0;
	while (msg[i])
	{
		flag = ft_atob(pid, msg[i]);
		if (flag == -1)
		{
			free(msg);
			ft_print_error("Signal could not be sent. Check PID.");
		}
		i++;
	}
	free(msg);
	return (0);
}

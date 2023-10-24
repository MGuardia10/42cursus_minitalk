/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:29:10 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/24 16:03:06 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		ft_print_error("Check args.\n\n\tUsage: ./client <PID> <MESSAGE>\n\n");
	i = 0;
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i]))
			ft_print_error("invalid PID.\n");
		i++;
	}
	if (!argv[2][0])
		ft_print_error("Invalid Message.\n");
}

void	ft_atob(int pid, char c)
{
	int i = 0;

	while (i < 8)
	{
		if (c & (0x01 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int pid;
	char *msg;

	check_args(argc, argv);
	pid = ft_atoi(argv[1]);
	msg = ft_strjoin(argv[2], "\n");
	if (!msg)
		return (1);
	while (*msg)
	{
		ft_atob(pid, *msg);
		msg++;
	}
	return (0);
}

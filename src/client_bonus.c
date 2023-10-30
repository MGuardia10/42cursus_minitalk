/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:55:55 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/25 12:23:16 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

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

void	ft_success(int signal, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signal == SIGUSR1)
		printf("Message sent succesfully to PID ===> %d\n", info->si_pid);
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

int	send_msg(char *msg, int pid)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (msg[++i])
	{
		flag = ft_atob(pid, msg[i]);
		if (flag == -1)
			return (flag);
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	char				*msg;
	int					flag;

	check_args(argc, argv);
	sa.sa_sigaction = &ft_success;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	pid = ft_atoi(argv[1]);
	msg = ft_strjoin(argv[2], "\n");
	if (!msg)
		return (STDERR);
	flag = send_msg(msg, pid);
	if (flag == -1)
	{
		free(msg);
		ft_print_error("Signal could not be sent. Check PID.");
	}
	sigaction(SIGUSR1, &sa, NULL);
	ft_atob(pid, '\0');
	free(msg);
	return (0);
}

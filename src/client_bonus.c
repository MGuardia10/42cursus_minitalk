/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:55:55 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/24 15:55:25 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

/*
- norminette
- leaks
- revisar uso sigaction
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
			ft_print_error("invalid PID.\n");
		i++;
	}
	if (!argv[2][0])
		ft_print_error("Invalid Message.\n");
}

void    ft_success(int signal, siginfo_t *info, void *ucontext)
{
    (void)ucontext;

    if (signal == SIGUSR1)
        printf("Message sent succesfully to PID ===> %d\n", info->si_pid);
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
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	char *msg;
	struct	sigaction sa;

	check_args(argc, argv);
    sa.sa_sigaction = &ft_success;
	pid = ft_atoi(argv[1]);
	msg = ft_strjoin(argv[2], "\n");
	if (!msg)
		return (1);
	while (*msg)
	{
		ft_atob(pid, *msg);
		msg++;
	}
	sigaction(SIGUSR1, &sa, NULL);
    ft_atob(pid, '\0');
	return (0);
}
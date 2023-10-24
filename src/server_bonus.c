/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:05:51 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/24 15:30:01 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	ft_btoa(int signal, siginfo_t *info, void *ucontext)
{
	static int i;
	static int bit;
	(void)ucontext;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
        if (i == 0)
            kill(info->si_pid, SIGUSR1);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	(void)argv;
	struct	sigaction sa;

	sa.sa_sigaction = &ft_btoa;
	if (argc != 1)
		ft_print_error("Server does not need arguments.");
	pid = getpid();
	ft_printf("Server running...\n\n	PID =====> %d\n", pid);
	ft_printf("\nMESSAGES RECEIVED:\n-------------------\n");
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}

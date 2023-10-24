/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:29:21 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/24 18:54:51 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_btoa(int signal)
{
	static int i;
	static int bit;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	(void)	argv;
	struct	sigaction sa;

	sa.sa_handler = &ft_btoa;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:29:21 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/23 16:43:43 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
- Imprimir errores pro la salida de errores.

*/

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 1)
		ft_print_error("Server does not need arguments.");
	pid = getpid();
	ft_printf("Server running...\n\n	PID =====> %d\n", pid);
	ft_printf("\nMESSAGES RECEIVED:\n------------------\n");
	while (1)
	{
		pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:29:10 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/23 16:41:59 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	return (0);
}

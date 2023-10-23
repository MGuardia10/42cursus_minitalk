/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:31:00 by mguardia          #+#    #+#             */
/*   Updated: 2023/10/23 16:31:04 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(char *error)
{
	write(STDERR, "Error: ", 7);
	ft_putstr_fd(error, STDERR);
	exit(EXIT_FAILURE);
}

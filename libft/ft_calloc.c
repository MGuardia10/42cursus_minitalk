/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:03:46 by mguardia          #+#    #+#             */
/*   Updated: 2023/09/21 15:03:12 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	arr = (void *)malloc(count * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, (count * size));
	return (arr);
}

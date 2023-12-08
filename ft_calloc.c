/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 05:01:53 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/06 13:08:10 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	allocated_size;

	if (count > 2147483647 || size > 2147483647)
		return (NULL);
	allocated_size = count * size;
	ptr = malloc(allocated_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, allocated_size);
	return (ptr);
}

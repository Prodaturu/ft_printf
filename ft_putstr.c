/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:07:27 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:51:08 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

size_t	ft_putstr(char *s)
{
	size_t	count;

	count = 0;
	if (s != NULL)
	{
		while (*s)
		{
			write(1, s, 1);
			s++;
			count++;
		}
	}
	return (count);
}

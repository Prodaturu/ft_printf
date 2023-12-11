/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:29:45 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/22 18:37:09 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

size_t	zero_padding(size_t padding)
{
	size_t	count;

	count = 0;
	while (padding)
	{
		count += ft_putchar('0');
		padding--;
	}
	return (count);
}

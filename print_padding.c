/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:29:45 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:15 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

size_t	print_padding(size_t padding)
{
	size_t	count;

	count = 0;
	while (padding)
	{
		count += ft_putchar(' ');
		padding--;
	}
	return (count);
}

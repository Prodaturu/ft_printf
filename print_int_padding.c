/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:26:59 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:11 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_int_padding(int pad_width, char pad_char)
{
	int	count;

	count = 0;
	while (pad_width > 0)
	{
		count += ft_putchar(pad_char);
		pad_width--;
	}
	return (count);
}

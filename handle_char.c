/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:02:05 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:51:57 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	handle_char_minus(t_format format_info, int c)
{
	int		count;

	count = 0;
	count += ft_putchar(c);
	while ((format_info.width) > 1)
	{
		count += ft_putchar(' ');
		format_info.width--;
	}
	return (count);
}

int	handle_char(t_format format_info, va_list args)
{
	int		count;
	char	c;

	c = va_arg(args, int);
	count = 0;
	if (format_info.minus == 1)
		count += handle_char_minus(format_info, c);
	else
	{
		while (format_info.width > 1)
		{
			count += ft_putchar(' ');
			format_info.width--;
		}
		count += ft_putchar(c);
	}
	return (count);
}

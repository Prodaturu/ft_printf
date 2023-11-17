/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 01:02:05 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/17 01:38:49 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	handle_char(t_format format_info, va_list args)
{
	int		count;
	char	c;

	c = va_arg(args, int);
	count = 0;
	if (format_info.minus == 1)
	{
		count = handle_char_minus(format_info, args);
		return (count);
	}
	else
	{
		while (--format_info.width > 0)
		{
			ft_putchar(' ');
			count++;
		}
		ft_putchar(c);
		count++;
	}
	return (count);
}

int	handle_char_minus(t_format format_info, va_list args)
{
	char	c;
	int		count;

	c = va_arg(args, int);
	count = 0;
	ft_putchar(c);
	count++;
	while (--format_info.width > 0)
	{
		ft_putchar(' ');
		count++;
	}
}

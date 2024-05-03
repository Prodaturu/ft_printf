/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:51 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:59:51 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format_str, ...)
{
	va_list		args;
	int			printed_char_count;
	t_format	format_information;

	printed_char_count = 0;
	va_start(args, format_str);
	while (*format_str)
	{
		if (*format_str == '%')
		{
			format_str++;
			format_information = parse_format(&format_str);
			printed_char_count += handle_format(format_information, args);
		}
		else
			printed_char_count += ft_putchar(*format_str);
		format_str++;
	}
	return (va_end(args), printed_char_count);
}

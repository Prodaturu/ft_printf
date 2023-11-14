/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:51 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/14 07:40:41 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printf(const char *format_str, ...)
{
	va_list		args;
	int			printed_char_count;
	const char	*current;
	t_format	format_information;

	current = format_str;
	va_start(args, format_str);
	while (*current)
	{
		if (*current == '%')
		{
			current++;
			format_information = parse_format(&current);
			printed_char_count = handle_format(format_information, args);
		}
		else
		{
			ft_putchar(*current);
			printed_char_count++;
		}
		current++;
	}
	return (va_end(args), printed_char_count);
}

// parse_format(&current, args):
	// fn to parse format specifier and flags.
// handle_format(format_information, args):
	// fn to call appropriate helper fn based on format specifier.
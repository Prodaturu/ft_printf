/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:14:46 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:52:01 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	handle_format(t_format format_info, va_list args)
{
	int	char_count;

	char_count = 0;
	if (format_info.specifier == 'c')
		char_count = handle_char(format_info, args);
	if (format_info.specifier == 's')
		char_count += handle_str(format_info, args);
	if (format_info.specifier == '%')
		char_count += handle_percent(format_info);
	if (format_info.specifier == 'd' || format_info.specifier == 'i')
		char_count += handle_int(&format_info, va_arg(args, int));
	if (format_info.specifier == 'u')
		char_count += handle_uint(&format_info, va_arg(args, unsigned int));
	if (format_info.specifier == 'x' || format_info.specifier == 'X')
		char_count += handle_hexa(format_info, va_arg(args, unsigned int));
	if (format_info.specifier == 'p')
		char_count += handle_pointer(format_info, va_arg(args, void *));
	return (char_count);
}

	// if (format_info.specifier == 'd' || format_info.specifier == 'i')
	// 	char_count += handle_int(&format_info, va_arg(args, int));
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:14:46 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/14 07:27:51 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	handle_format(t_format format_info, va_list args)
{
	int	printed_chars_count;

	printed_chars_count = 0;
	if (format_info.specifier == 'c')
		printed_chars_count = handle_char(format_info, args);
	else if (format_info.specifier == 's')
		printed_chars_count = handle_string(format_info, args);
	else if (format_info.specifier == 'd')
		printed_chars_count = handle_string(format_info, args);
	else if (format_info.specifier == 'i')
		printed_chars_count = handle_int(format_info, args);
	else if (format_info.specifier == 'u')
		printed_chars_count = handle_unsign_decimal(format_info, args);
	else if (format_info.specifier == 'x')
		printed_chars_count = handle_lowerhexa(format_info, args);
	else if (format_info.specifier == 'X')
		printed_chars_count = handle_upperhexa(format_info, args);
	else if (format_info.specifier == 'p')
		printed_chars_count = handle_pointer(format_info, args);
	return (printed_chars_count);
}

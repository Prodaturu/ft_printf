/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:43:39 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:54:51 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	initialize_format_info(t_format	*format_info)
{
	format_info->width = 0;
	format_info->precision = -1;
	format_info->minus = 0;
	format_info->zero = 0;
	format_info->dot = 0;
	format_info->hash = 0;
	format_info->space = 0;
	format_info->plus = 0;
	format_info->specifier = 0;
}

// change the t_format struct based on flags found

static void	parse_flags(const char **currents_ptr, t_format *format_info)
{
	while (is_flag(**currents_ptr))
	{
		if (**currents_ptr == '-')
			format_info->minus = 1;
		else if (**currents_ptr == '+')
			format_info->plus = 1;
		else if (**currents_ptr == ' ')
			format_info->space = 1;
		else if (**currents_ptr == '#')
			format_info->hash = 1;
		else if (**currents_ptr == '0')
			format_info->zero = 1;
		(*currents_ptr)++;
	}
}

static void	parse_width(const char **currents_ptr, t_format *format_info)
{
	int	width_in_num;

	width_in_num = 0;
	while (ft_isdigit(**currents_ptr))
	{
		width_in_num = ((width_in_num) * 10) + (**currents_ptr - '0');
		(*currents_ptr)++;
	}
	format_info->width = width_in_num;
}

static void	parse_precision(const char **currents_ptr, t_format *format_info)
{
	int	precision_in_num;

	precision_in_num = 0;
	if (**currents_ptr == '.')
		(*currents_ptr)++;
	while (ft_isdigit(**currents_ptr))
	{
		precision_in_num = (precision_in_num * 10) + (**currents_ptr - '0');
		(*currents_ptr)++;
	}
	format_info->precision = precision_in_num;
}

// ft_parse formate should parse the string and change the t_format struct

t_format	parse_format(const char **currents_ptr)
{
	t_format	format_info;

	initialize_format_info(&format_info);
	while (**currents_ptr)
	{
		if (is_flag(**currents_ptr))
			parse_flags(currents_ptr, &format_info);
		else if (ft_isdigit(**currents_ptr))
			parse_width(currents_ptr, &format_info);
		else if (**currents_ptr == '.')
			parse_precision(currents_ptr, &format_info);
		else if (!format_info.specifier)
		{
			format_info.specifier = **currents_ptr;
			break ;
		}
		else
			(*currents_ptr)++;
	}
	return (format_info);
}

// t_format	parse_format(const char **currents_ptr)
// {
// 	t_format	format_info;

// 	initialize_format_info(&format_info);
// 	while (**currents_ptr)
// 	{
// 		if (is_flag(**currents_ptr))
// 			parse_flags(currents_ptr, &format_info);
// 		else if (ft_isdigit(**currents_ptr))
// 			parse_width(currents_ptr, &format_info);
// 		else if (**currents_ptr == '.')
// 			parse_precision(currents_ptr, &format_info);
// 		else if (**currents_ptr == '%' && !format_info.specifier)
// 		{
// 			(*currents_ptr)++;
// 			if (**currents_ptr != '%')
// 			{
// 				format_info.specifier = '%';
// 				break ;
// 			}
// 		}
// 		else if (!format_info.specifier)
// 		{
// 			format_info.specifier = **currents_ptr;
// 			break ;
// 		}
// 		else
// 			(*currents_ptr)++;
// 	}
// 	return (format_info);
// }

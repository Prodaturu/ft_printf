/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:43:39 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/13 22:33:53 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

// static void	initialize_format_info(t_format	*format_info)
// {
// 	format_info->width = 0;
// 	format_info->minus = 0;
// 	format_info->zero = 0;
// 	format_info->dot = 0;
// 	format_info->hash = 0;
// 	format_info->space = 0;
// 	format_info->plus = 0;
// 	format_info->specifier = 0;
// }

static void parse_flags(const **format, t_format *format_info)
{
	int flag_found;

	while is_flag(**str)
	{
		if
	}
}

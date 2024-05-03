/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:31:23 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:53:07 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	handle_int_flags(t_format *format_info, int value, int *is_negative)
{
	if (value < 0)
	{
		*is_negative = 1;
		format_info->space = 0;
		format_info->plus = 0;
	}
	if (format_info->minus)
		format_info->zero = 0;
	if (format_info->precision >= 0)
		format_info->zero = 0;
}

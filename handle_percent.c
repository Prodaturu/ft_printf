/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:55:42 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:53:16 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	handle_percent(t_format format_info)
{
	size_t	count;
	size_t	padding;

	count = 0;
	padding = calculate_padding(format_info, 1);
	if (!format_info.minus)
		count += print_padding(padding);
	count += ft_putchar('%');
	if (format_info.minus)
		count += print_padding(padding);
	return (count);
}

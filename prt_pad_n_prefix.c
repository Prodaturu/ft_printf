/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_pad_n_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:14:23 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:24 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	prt_pad_n_prefix(t_format f_info, int *values)
{
	int	count;

	count = 0;
	if (f_info.zero && values[1] > 0)
	{
		count += print_hex_prefix(f_info.specifier);
		count += prnt_hexpad(values[3], '0');
	}
	else
	{
		if (!f_info.minus && values[3] > 0)
		{
			if (f_info.zero)
				count += prnt_hexpad(values[3], '0');
			else
				count += prnt_hexpad(values[3], ' ');
		}
		if (values[1] > 0)
			count += print_hex_prefix(f_info.specifier);
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:13:38 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:50:10 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	add_sign(t_format *f_info, int is_neg)
{
	int	count;

	count = 0;
	if (is_neg)
		count += write(1, "-", 1);
	else if (f_info->plus)
		count += write(1, "+", 1);
	else if (f_info->space)
		count += write(1, " ", 1);
	return (count);
}

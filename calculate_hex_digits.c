/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_hex_digits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:45:06 by sprodatu          #+#    #+#             */
/*   Updated: 2023/12/08 06:49:12 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	calculate_hex_digits(uintptr_t num)
{
	int		digits;

	digits = 0;
	if (num == 0)
		digits = 1;
	while (num != 0)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

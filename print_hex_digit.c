/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:20:17 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:54:55 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_hex_digit(unsigned int digit, int case_type)
{
	if (digit < 10)
		return (ft_putchar('0' + digit));
	else
	{
		if (case_type)
			return (ft_putchar('A' + digit - 10));
		else
			return (ft_putchar('a' + digit - 10));
	}
}

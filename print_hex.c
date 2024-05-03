/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:02:10 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:05 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_hex(unsigned int num, int case_type, int num_digits)
{
	int				count;
	unsigned int	digit;
	int				i;
	unsigned int	divisor;

	count = 0;
	divisor = 1;
	i = 1;
	while (i < num_digits)
	{
		++i;
		divisor *= 16;
	}
	i = 0;
	while (i < num_digits)
	{
		++i;
		digit = (num / divisor) % 16;
		count += print_hex_digit(digit, case_type);
		divisor /= 16;
	}
	return (count);
}

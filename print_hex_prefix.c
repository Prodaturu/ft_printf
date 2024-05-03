/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_prefix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:33 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:00 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	print_hex_prefix(char specifier)
{
	if (specifier == 'X')
		return (ft_putstr("0X"));
	else
		return (ft_putstr("0x"));
	return (-1);
}

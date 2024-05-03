/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_hexpad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:40:21 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:20 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	prnt_hexpad(int pad_len, char pad_char)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < pad_len)
	{
		count += ft_putchar(pad_char);
		i++;
	}
	return (count);
}

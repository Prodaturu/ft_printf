/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:17:02 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:49:59 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	add_padding(char *str, int num_len, int precision, int is_neg)
{
	size_t	length;
	size_t	index;

	if (num_len >= precision)
		return ;
	length = precision + is_neg;
	index = length;
	while (index > (size_t)(precision - num_len + is_neg))
		str[index - 1] = str[index - 1 - (precision - num_len)];
	index = is_neg;
	while (index < (size_t)(precision - num_len + is_neg))
		str[index] = '0';
	if (is_neg)
		str[0] = '-';
}

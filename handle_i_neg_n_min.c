/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i_neg_n_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:25:54 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:53:01 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*handle_i_neg_n_min(int *value, int *is_neg)
{
	char	*val_str;

	if (*value == INT_MIN)
	{
		val_str = ft_strdup("2147483648");
		*is_neg = 1;
	}
	else
	{
		if (*is_neg)
			*value = -*value;
		val_str = ft_itoa(*value);
	}
	return (val_str);
}

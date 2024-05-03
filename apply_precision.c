/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:42:16 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:48:30 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*apply_precision(char *value_str, int precision)
{
	int		original_len;
	int		total_len;
	int		i;
	char	*new_str;

	original_len = ft_strlen(value_str);
	total_len = precision;
	i = 0;
	if (precision == 0 && value_str[0] == '0' && value_str[1] == '\0')
		return (ft_strdup(""));
	if (precision <= original_len)
		return (ft_strdup(value_str));
	new_str = malloc(total_len + 1);
	if (!new_str)
		return (NULL);
	original_len = ft_strlen(value_str);
	total_len = precision;
	while (i < precision - original_len)
		new_str[i++] = '0';
	ft_strcpy(new_str + i, value_str);
	return (new_str);
}

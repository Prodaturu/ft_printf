/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 05:02:37 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:53:13 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*handle_int_min_and_convert(int value, int *is_neg)
{
	char	*val_str;

	if (value == INT_MIN)
	{
		val_str = ft_strdup("2147483648");
		*is_neg = 1;
	}
	else
	{
		if (*is_neg)
			value = -value;
		val_str = ft_itoa(value);
	}
	return (val_str);
}

int	handle_minus_true(t_format *f_info, char *fin_str, int is_neg)
{
	int	count;
	int	pad_width;

	count = 0;
	pad_width = f_info->width - ft_strlen(fin_str);
	if (f_info->space || is_neg || f_info->plus)
		pad_width -= 1;
	count += add_sign(f_info, is_neg);
	while (*fin_str)
		count += write(1, fin_str++, 1);
	while (pad_width > 0)
	{
		count += write(1, " ", 1);
		pad_width--;
	}
	return (count);
}

int	handle_minus_false_zero_true(t_format *f_info, char *fin_str, int is_neg)
{
	int	count;
	int	pad_width;

	count = 0;
	pad_width = f_info->width - ft_strlen(fin_str);
	if (f_info->space || is_neg || f_info->plus)
		pad_width -= 1;
	if (is_neg)
		count += write(1, "-", 1);
	else if (f_info->space)
		count += write(1, " ", 1);
	else if (f_info->plus)
		count += write(1, "+", 1);
	while (pad_width > 0)
	{
		count += write(1, "0", 1);
		pad_width--;
	}
	while (*fin_str)
		count += write(1, fin_str++, 1);
	return (count);
}

int	handle_minus_false_zero_false(t_format *f_info, char *fin_str, int is_neg)
{
	int	count;
	int	pad_width;

	count = 0;
	pad_width = f_info->width - ft_strlen(fin_str);
	if (f_info->space || is_neg || f_info->plus)
		pad_width -= 1;
	while (pad_width > 0)
	{
		count += write(1, " ", 1);
		pad_width--;
	}
	count += add_sign(f_info, is_neg);
	while (*fin_str)
		count += write(1, fin_str++, 1);
	return (count);
}

int	handle_int(t_format *f_info, int value)
{
	int		count;
	int		is_neg;
	char	*val_str;
	char	*prec_str;
	char	*fin_str;

	count = 0;
	is_neg = value < 0;
	handle_int_flags(f_info, value, &is_neg);
	val_str = handle_int_min_and_convert(value, &is_neg);
	prec_str = apply_precision(val_str, f_info->precision);
	if (!prec_str)
		return (free(prec_str), -1);
	if (val_str != prec_str)
		free(val_str);
	fin_str = prec_str;
	if (f_info->minus)
		count += handle_minus_true(f_info, fin_str, is_neg);
	else if (f_info->zero)
		count += handle_minus_false_zero_true(f_info, fin_str, is_neg);
	else
		count += handle_minus_false_zero_false(f_info, fin_str, is_neg);
	return (free(prec_str), count);
}

// if (value == INT_MIN)
// {
// 	val_str = ft_strdup("2147483648");
// 	is_neg = 1;
// }
// else
// {
// 	if (is_neg)
// 		value = -value;
// 	val_str = ft_itoa(value);
// }

// f_info->minus is true
	// {
	// 	pad_width = f_info->width - ft_strlen(fin_str);
	// 	if (f_info->space || is_neg || f_info->plus)
	// 		pad_width -= 1;
	// 	if (is_neg)
	// 		count += write(1, "-", 1);
	// 	if (f_info->space)
	// 		count += write(1, " ", 1);
	// 	if (f_info->plus)
	// 		count += write(1, "+", 1);
	// 	while (*fin_str)
	// 		count += write(1, fin_str++, 1);
	// 	while (pad_width > 0)
	// 	{
	// 		count += write(1, " ", 1);
	// 		pad_width--;
	// 	}
	// }
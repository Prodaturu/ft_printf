/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:47:26 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:54:43 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

// needs correcction
char	*apply_uprecision(char *value_str, int precision)
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

int	handle_uint(t_format *f_info, unsigned int value)
{
	int		values[2];
	char	*val_str;
	char	*prec_str;
	char	*fin_str;
	char	pad_char;

	values[0] = 0;
	val_str = ft_utoa(value);
	prec_str = apply_uprecision(val_str, f_info->precision);
	if (!prec_str)
		return (free(prec_str), -1);
	if (val_str != prec_str)
		free(val_str);
	fin_str = prec_str;
	values[1] = f_info->width - ft_strlen(fin_str);
	pad_char = ' ';
	if (f_info->zero && f_info->precision < 0 && !f_info->minus)
		pad_char = '0';
	while (!f_info->minus && values[1]-- > 0)
		values[0] += write(1, &pad_char, 1);
	while (*fin_str)
		values[0] += write(1, fin_str++, 1);
	while (f_info->minus && values[1]-- > 0)
		values[0] += write(1, " ", 1);
	return (free(prec_str), values[0]);
}

// fucl it
// char	*apply_uprecision(char *value_str, int precision)
// {
// 	int		original_len;
// 	int		total_len;
// 	int		i;
// 	char	*new_str;

// 	original_len = ft_strlen(value_str);
// 	total_len = precision;
// 	i = 0;
// 	if (precision == 0 && value_str[0] == '0' && value_str[1] == '\0')
// 		return (ft_strdup(""));
// 	if (precision <= original_len)
// 		return (ft_strdup(value_str));
// 	new_str = malloc(total_len + 1);
// 	if (!new_str)
// 		return (NULL);
// 	original_len = ft_strlen(value_str);
// 	total_len = precision;
// 	while (i < precision - original_len)
// 		new_str[i++] = '0';
// 	ft_strcpy(new_str + i, value_str);
// 	return (new_str);
// }

// int	handle_uint_minus_flag(int *values, char *fin_str)
// {
// 	int	count;

// 	count = 0;
// 	while (values[1] > 0)
// 	{
// 		count += write(1, " ", 1);
// 		values[1]--;
// 	}
// 	while (*fin_str)
// 		count += write(1, fin_str++, 1);
// 	return (count);
// }

// int	handle_uint_non_minus_flag(int *values, char *fin_str, char pad_char)
// {
// 	int	count;

// 	count = 0;
// 	while (values[1] > 0)
// 	{
// 		count += write(1, &pad_char, 1);
// 		values[1]--;
// 	}
// 	while (*fin_str)
// 		count += write(1, fin_str++, 1);
// 	return (count);
// }

// int	handle_uint(t_format *f_info, unsigned int value)
// {
// 	int		values[2];
// 	char	*val_str;
// 	char	*prec_str;
// 	char	*fin_str;
// 	char	pad_char;

// 	values[0] = 0;
// 	values[1] = 0;
// 	val_str = ft_utoa(value);
// 	prec_str = apply_uprecision(val_str, f_info->precision);
// 	if (!prec_str)
// 		return (free(prec_str), -1);
// 	if (val_str != prec_str)
// 		free(val_str);
// 	fin_str = prec_str;
// 	values[1] = f_info->width - ft_strlen(fin_str);
// 	pad_char = ' ';
// 	if (f_info->zero && f_info->precision < 0 && !f_info->minus)
// 		pad_char = '0';
// 	if (f_info->minus)
// 		values[0] += handle_uint_minus_flag(values, fin_str);
// 	else
// 		values[0] += handle_uint_non_minus_flag(values, fin_str, pad_char);
// 	return (free(prec_str), values[0]);
// }

// prev

// char	*apply_uprecision(char *value_str, int precision)
// {
// 	int		original_len;
// 	int		total_len;
// 	int		i;
// 	char	*new_str;

// 	original_len = ft_strlen(value_str);
// 	total_len = precision;
// 	i = 0;
// 	if (precision == 0 && value_str[0] == '0' && value_str[1] == '\0')
// 		return (ft_strdup(""));
// 	if (precision <= original_len)
// 		return (ft_strdup(value_str));
// 	new_str = malloc(total_len + 1);
// 	if (!new_str)
// 		return (NULL);
// 	original_len = ft_strlen(value_str);
// 	total_len = precision;
// 	while (i < precision - original_len)
// 		new_str[i++] = '0';
// 	ft_strcpy(new_str + i, value_str);
// 	return (new_str);
// }

// int	handle_uint(t_format *f_info, unsigned int value)
// {
// 	int		count;
// 	int		pad_width;
// 	char	*val_str;
// 	char	*prec_str;
// 	char	*fin_str;
// 	char	pad_char;

// 	count = 0;
// 	val_str = ft_utoa(value);
// 	prec_str = apply_uprecision(val_str, f_info->precision);
// 	if (!prec_str)
// 		return (free(prec_str), -1);
// 	if (val_str != prec_str)
// 		free(val_str);
// 	fin_str = prec_str;
// 	pad_width = f_info->width - ft_strlen(fin_str);
// 	pad_char = ' ';
// 	if (f_info->zero && f_info->precision < 0 && !f_info->minus)
// 		pad_char = '0';
// 	if (!f_info->minus)
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, &pad_char, 1);
// 			pad_width--;
// 		}
// 	}
// 	while (*fin_str)
// 		count += write(1, fin_str++, 1);
// 	if (f_info->minus)
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, " ", 1);
// 			pad_width--;
// 		}
// 	}
// 	return (free(prec_str), count);
// }

	// if (!f_info->minus)
	// {
	// 	while (pad_width > 0)
	// 	{
	// 		count += write(1, &pad_char, 1);
	// 		pad_width--;
	// 	}
	// }
	// while (*fin_str)
	// 	count += write(1, fin_str++, 1);
	// if (f_info->minus)
	// {
	// 	while (pad_width > 0)
	// 	{
	// 		count += write(1, " ", 1);
	// 		pad_width--;
	// 	}
	// }

// int	prt_frmtd_uint(t_format *f_info, size_t pad_width, char pad_char)
// {
// 	int	count;

// 	count = 0;
// 	if (!f_info->minus)
// 	{
// 		if (pad_char == '0')
// 			count += zero_padding(pad_width);
// 		else
// 			count += print_padding(pad_width);
// 	}
// 	return (count);
// }

// int	handle_uint(t_format *f_info, unsigned int value)
// {
// 	int		values[2];
// 	char	strings[3];

// 	values[0] = 0;
// 	strings[0] = ft_utoa(value);
// 	strings[1] = apply_uprecision(strings[0], f_info->precision);
// 	if (!strings[1])
// 		return (free(strings[0]), -1);
// 	if (strings[0] != strings[1])
// 		free(strings[0]);
// 	strings[2] = ' ';
// 	if (f_info->zero && f_info->precision < 0 && !f_info->minus)
// 		strings[2] = '0';
// 	values[1] = calculate_padding(*f_info, ft_strlen(strings[1]));
// 	values[0] += prt_frmtd_uint(f_info, values[1], strings[2]);
// 	if (!f_info->minus)
// 	{
// 		values[0] += prt_frmtd_uint(f_info, values[1], strings[2]);
// 		values[0] += ft_putstr(strings[1]);
// 	}
// 	else
// 	{
// 		values[0] += ft_putstr(strings[1]);
// 		values[0] += prt_frmtd_uint(f_info, values[1], strings[2]);
// 	}
// 	return (free(strings[1]), values[0]);
// }

// // latest working: 
// int	handle_uint(t_format *f_info, unsigned int value)
// {
// 	int		count;
// 	int		pad_width;
// 	char	*val_str;
// 	char	*prec_str;
// 	char	*fin_str;
// 	char	pad_char;

// 	count = 0;
// 	val_str = ft_utoa(value);
// 	prec_str = apply_uprecision(val_str, f_info->precision);
// 	if (!prec_str)
// 		return (free(prec_str), -1);
// 	if (val_str != prec_str)
// 		free(val_str);
// 	fin_str = prec_str;
// 	pad_width = f_info->width - ft_strlen(fin_str);
// 	pad_char = ' ';
// 	if (f_info->zero && f_info->precision <0 && !f_info->minus)
// 		pad_char = '0';
// 	if (!f_info->minus)
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, &pad_char, 1);
// 			pad_width--;
// 		}
// 	}
// 	while (*fin_str)
// 		count += write(1, fin_str++, 1);
// 	if (f_info->minus)
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, " ", 1);
// 			pad_width--;
// 		}
// 	}
// 	return (free(prec_str), count);
// }

// version 2:

// char	*prepare_uint_string(unsigned int val, t_format *f_info)
// {
// 	char	*val_str;
// 	char	*prec_str;

// 	val_str = ft_utoa(val);
// 	prec_str = apply_uprecision(val_str, f_info->precision);
// 	if (val_str != prec_str)
// 		free(val_str);
// 	return (prec_str);
// }

// int	print_uint(char *str, t_format *f_info)
// {
// 	int		count;
// 	int		pad_width;
// 	char	pad_char;

// 	pad_width = f_info->width - ft_strlen(str);
// 	pad_char = ' ';
// 	count = 0;
// 	if (!f_info->minus)
// 	{
// 		if (f_info->zero && f_info->precision < 0 && !f_info->minus)
// 			count += zero_padding(pad_width);
// 		else
// 			count += print_padding(pad_width);
// 	}
// 	count += ft_putstr(str);
// 	if (f_info->minus)
// 		count += print_padding(pad_width);
// 	return (count);
// }

// int	handle_uint(t_format *f_info, unsigned int value)
// {
// 	char	*fin_str;
// 	int		count;

// 	count = 0;
// 	fin_str = prepare_uint_string(value, f_info);
// 	if (!fin_str)
// 		return (-1);
// 	count += print_uint(fin_str, f_info);
// 	free(fin_str);
// 	return (count);
// }

//XX
// Old versiond of code (or) Unused code:
//XX

// void	handle_uint_flags(t_format *format_info)
// {
// 	if (format_info->minus)
// 		format_info->zero = 0;
// 	if (format_info->precision >= 0)
// 		format_info->zero = 0;
// }

// pad_char = (f_info->zero && f_info->precision < 0 
// && !f_info->minus) ? '0' : ' ';
// int	handle_uint(t_format *f_info, unsigned int value)
// {
// 	int		count;
// 	int		pad_width;
// 	char	*val_str;
// 	char	*prec_str;
// 	char	*fin_str;

// 	count = 0;
// 	val_str = ft_utoa(value);
// 	prec_str = apply_uprecision(val_str, f_info->precision);
// 	if (!prec_str)
// 		return (free(prec_str), -1);
// 	if (val_str != prec_str)
// 		free(val_str);
// 	fin_str = prec_str;
// 	pad_width = f_info->width - ft_strlen(fin_str);
// 	if (!f_info->minus && f_info->zero && f_info->precision < 0)
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, "0", 1);
// 			pad_width--;
// 		}
// 	}
// 	if (!f_info->minus && (!f_info->zero || f_info->precision > 0))
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, fin_str++, 1);
// 			pad_width--;
// 		}
// 	}
// 	while (*fin_str)
// 		count += write(1, fin_str++, 1);
// 	if (f_info->minus)
// 	{
// 		while (pad_width > 0)
// 		{
// 			count += write(1, fin_str++, 1);
// 			pad_width--;
// 		}
// 	}
// 	return (free(prec_str), count);
// }

	// if (f_info->minus)
	// {
	// 	pad_width = f_info->width - ft_strlen(fin_str);
	// 	if (f_info->space || f_info->plus)
	// 		pad_width -= 1;
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
	// if (!f_info->minus)
	// {
	// 	pad_width = f_info->width - ft_strlen(prec_str);
	// 	if (f_info->zero)
	// 	{
	// 		if (f_info->space || f_info->plus)
	// 		{
	// 			pad_width -= 1;
	// 			if (f_info->space)
	// 				count += write(1, " ", 1);
	// 			if (f_info->plus)
	// 				count += write(1, "+", 1);
	// 		}
	// 		while (pad_width > 0)
	// 		{
	// 			count += write(1, "0", 1);
	// 			pad_width--;
	// 		}
	// 		while (*fin_str)
	// 			count += write(1, fin_str++, 1);
	// 	}
	// 	if (!f_info->zero)
	// 	{
	// 		if (f_info->space || f_info->plus)
	// 			pad_width -= 1;
	// 		while (pad_width > 0)
	// 		{
	// 			count += write(1, " ", 1);
	// 			pad_width--;
	// 		}
	// 		if (f_info->space || f_info->plus)
	// 		{
	// 			if (f_info->space)
	// 				count += write(1, " ", 1);
	// 			if (f_info->plus)
	// 				count += write(1, "+", 1);
	// 		}
	// 		while (*fin_str)
	// 			count += write(1, fin_str++, 1);
	// 	}
	// }

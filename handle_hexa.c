/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 03:05:32 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:52:55 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	handle_hexa(t_format f_info, unsigned int num)
{
	int	case_type;

	case_type = 0;
	if (f_info.specifier == 'x' || f_info.specifier == 'X')
	{
		if (f_info.specifier == 'X')
			case_type = 1;
		if (f_info.minus || f_info.precision >= 0)
			f_info.zero = 0;
	}
	return (put_hexa(num, case_type, f_info));
}

// int	print_hex_digit(unsigned int digit, int case_type)
// {
// 	if (digit < 10)
// 		return (ft_putchar('0' + digit));
// 	else
// 	{
// 		if (case_type)
// 			return (ft_putchar('A' + digit - 10));
// 		else
// 			return (ft_putchar('a' + digit - 10));
// 	}
// }

// static int	prt_pad_n_prefix(t_format f_info, int *values)
// {
// 	int	count;

// 	count = 0;
// 	if (f_info.zero && values[1] > 0)
// 	{
// 		count += print_hex_prefix(f_info.specifier);
// 		count += prnt_hexpad(values[3], '0');
// 	}
// 	else
// 	{
// 		if (!f_info.minus && values[3] > 0)
// 			count += prnt_hexpad(values[3], f_info.zero ? '0' : ' ');
// 		if (values[1] > 0)
// 			count += print_hex_prefix(f_info.specifier);
// 	}
// 	return (count);
// }

// static int	print_hex(unsigned int num, int case_type, int num_digits)
// {
// 	int				count;
// 	unsigned int	digit;
// 	int				i;
// 	unsigned int	divisor;

// 	count = 0;
// 	divisor = 1;
// 	i = 1;
// 	while (i < num_digits)
// 	{
// 		++i;
// 		divisor *= 16;
// 	}
// 	i = 0;
// 	while (i < num_digits)
// 	{
// 		++i;
// 		digit = (num / divisor) % 16;
// 		count += print_hex_digit(digit, case_type);
// 		divisor /= 16;
// 	}
// 	return (count);
// }

// static int	put_hexa(unsigned int num, int case_type, t_format f_info)
// {
// 	int				count;
// 	unsigned int	temp_num;
// 	int				values[4];

// 	count = 0;
// 	values[0] = 1;
// 	temp_num = num;
// 	while (temp_num >>= 4)
// 		++values[0];
// 	values[1] = 0;
// 	if (f_info.hash && num != 0)
// 		values[1] = 2;
// 	values[2] = 0;
// 	if (f_info.precision > values[0])
// 		values[2] = f_info.precision - values[0];
// 	values[3] = f_info.width - values[0] - values[2] - values[1];
// 	if (num == 0 && f_info.precision == 0)
// 	{
// 		values[0] = 0;
// 		values[3] = f_info.width;
// 	}
// 	count += prt_pad_n_prefix(f_info, values);
// 	count += prnt_hexpad(values[2], '0');
// 	if (!(num == 0 && f_info.precision == 0))
// 		count += print_hex(num, case_type, values[0]);
// 	if (f_info.minus && values[3] > 0)
// 		count += prnt_hexpad(values[3], ' ');
// 	return (count);
// }
// Values array:
// v[0] -> num_digits;
// v[1] -> prefix_len;
// v[2] -> pad_len;
// v[3] -> width_len;

// void	handle_hexa_flags(t_format *f_info, unsigned int num)
// {
// 	int	a;

// 	a = num;
// 	if (f_info->minus || f_info->precision >= 0)
// 		f_info->zero = 0;
// }

// int	prnt_hexpad(int pad_len, char pad_char)
// {
// 	int	count;

// 	count = 0;
// 	while (pad_len > 0)
// 	{
// 		count += ft_putchar(pad_char);
// 		pad_len--;
// 	}
// 	return (count);
// }

// int	put_hexa(unsigned int num, int case_type, t_format f_info)
// {
// 	static char	upper[17] = "0123456789ABCDEF";
// 	static char	lower[17] = "0123456789abcdef";
// 	char		buffer[9];
// 	int			count;
// 	int			i;
// 	int			num_len;
// 	int			pad_len;
// 	int			width_len;
// 	int			prefix_len;

// 	count = 0;
// 	i = 8;
// 	buffer[i] = '\0';
// 	handle_hexa_flags(&f_info, num);
// 	prefix_len = 0;
// 	if (f_info.hash && num != 0)
// 		prefix_len = 2;
// 	if (num == 0)
// 	{
// 		if (f_info.precision == 0 && f_info.width == 0)
// 			return (0);
// 		else if (f_info.precision == 0 && f_info.width > 0)
// 		{
// 			width_len = f_info.width;
// 			while (width_len > 0)
// 			{
// 				if (f_info.zero)
// 				{
// 					buffer[--i] = '0';
// 					width_len--;
// 				}
// 				else
// 				{
// 					buffer[--i] = ' ';
// 					width_len--;
// 				}
// 			}
// 			count += ft_putstr(&buffer[i]);
// 			return (count);
// 		}
// 		else
// 			buffer[--i] = '0';
// 	}
// 	else
// 	{
// 		while (num != 0)
// 		{
// 			if (case_type)
// 				buffer[--i] = upper[num % 16];
// 			else
// 				buffer[--i] = lower[num % 16];
// 			num /= 16;
// 		}
// 	}
// 	num_len = 8 - i;
// 	pad_len = 0;
// 	if (f_info.precision > num_len)
// 		pad_len = f_info.precision - num_len;
// 	width_len = f_info.width - num_len - pad_len - prefix_len;
// 	if (!f_info.minus && width_len > 0)
// 	{
// 		if (f_info.zero)
// 		{
// 			if (prefix_len > 0)
// 			{
// 				if (case_type)
// 					count += ft_putstr("0X");
// 				else
// 					count += ft_putstr("0x");
// 			}
// 			count += prnt_hexpad(width_len, '0');
// 		}
// 		else
// 		{
// 			count += prnt_hexpad(width_len, ' ');
// 			if (prefix_len > 0)
// 			{
// 				if (case_type)
// 					count += ft_putstr("0X");
// 				else
// 					count += ft_putstr("0x");
// 			}
// 		}
// 	}
// 	else if (prefix_len > 0)
// 	{
// 		if (case_type)
// 			count += ft_putstr("0X");
// 		else
// 			count += ft_putstr("0x");
// 	}
// 	count += prnt_hexpad(pad_len, '0');
// 	count += ft_putstr(&buffer[i]);
// 	if (f_info.minus && width_len > 0)
// 		count += prnt_hexpad(width_len, ' ');
// 	return (count);
// }

// int	handle_hexa(t_format f_info, unsigned int num)
// {
// 	int	case_type;

// 	case_type = 0;
// 	if (f_info.specifier == 'X')
// 		case_type = 1;
// 	return (put_hexa(num, case_type, f_info));
// }

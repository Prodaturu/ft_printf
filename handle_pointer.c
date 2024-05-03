/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:01:08 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:54:25 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	prt_hex_digit(uintptr_t digit, int case_type)
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

int	prt_hex(uintptr_t num, int case_type)
{
	int			count;
	uintptr_t	digit;
	uintptr_t	divisor;
	int			num_digits;
	int			i;

	divisor = 1;
	num_digits = calculate_hex_digits(num);
	count = 0;
	i = 1;
	while (i < num_digits)
	{
		divisor *= 16;
		i++;
	}
	i = 0;
	while (i < num_digits)
	{
		digit = (num / divisor) % 16;
		count += prt_hex_digit(digit, case_type);
		divisor /= 16;
		i++;
	}
	return (count);
}

int	print_pointer_prefix(uintptr_t address, t_format format_info)
{
	int	count;

	count = ft_putstr("0x");
	if (address == 0 && format_info.precision != 0)
		return (count + ft_putchar('0'));
	return (count);
}

int	handle_pointer(t_format format_info, void *ptr)
{
	uintptr_t	address;
	int			count;
	int			num_digits;
	int			padding;

	address = (uintptr_t)ptr;
	num_digits = calculate_hex_digits(address) + 2;
	padding = format_info.width - num_digits;
	count = 0;
	if (!format_info.minus && padding > 0)
		count += print_padding(padding);
	count += print_pointer_prefix(address, format_info);
	if (address != 0)
		count += prt_hex(address, 0);
	if (format_info.minus && padding > 0)
		count += print_padding(padding);
	return (count);
}

// void put_ptr(uintptr_t address)
// {
// 	static char	digits[] = "0123456789abcdef";

// 	if (address >= 16)
// 		put_ptr(address / 16);
// 	else
// 		ft_putchar(digits[address % 16]);
// }

// int	handle_pointer(t_format format_info, void *ptr)
// {
// 	int			count;
// 	uintptr_t	address;

// 	count = 0;
// 	address = (uintptr_t)ptr;
// 	if (format_info.hash)
// 		count += ft_putstr("0x");
// 	if (address == 0)
// 		count += ft_putchar('0');
// 	else
// 		put_ptr(address);
// 	return (count);
// }

// void	handle_ptr_flags(t_format *f_info)
// {
// 	if (f_info->zero)
// 		f_info->zero = 0;
// 	if (f_info -> precision || f_info->precision == 0)
// 		f_info->precision = -1;
// 	if (f_info->dot)
// 		f_info->dot = 0;
// 	if (f_info->hash)
// 		f_info->hash = 0;
// 	f_info->specifier = 'x';
// }

// int	handle_pointer(t_format format_info, void *ptr)
// {
// 	// char	*buffer;
// 	int		count;

// 	count = 0;
// }

// static size_t	hexa_digits(unsigned int n)
// {
// 	size_t	digits;

// 	digits = 0;
// 	if (n == 0)
// 		return (1);
// 	while (n != 0)
// 	{
// 		digits += 1;
// 		n /= 16;
// 	}
// 	return (digits);
// }

// static void	put_hexa(unsigned int nbr, int upper_case)
// {
// 	static char	uppercase[] = "0123456789ABCDEF";
// 	static char	lowercase[] = "0123456789abcdef";

// 	if (nbr >= 16)
// 		put_hexa((nbr / 16), upper_case);
// 	if (upper_case)
// 		write(1, &uppercase[nbr % 16], 1);
// 	else
// 		write(1, &lowercase[nbr % 16], 1);
// }

// int	handle_ptr_hexa(t_format	f_info, unsigned int nbr, int upper_case)
// {
// 	if (f_info.zero)
// 		f_info.zero = 0;
// 	put_hexa(nbr, upper_case);
// 	return (hexa_digits(nbr));
// }

// int	handle_pointer(t_format format_info, void *ptr)
// {
// 	unsigned long	address;
// 	int				count;

// 	count = 0;
// 	address = (unsigned long) ptr;
// 	handle_ptr_flags(&format_info);
// 	if (ptr == NULL)
// 		return (ft_putstr("0x0"));
// 	count += ft_putstr("0x");
// 	count += handle_hexa(format_info, address);
// 	return (count);
// }

// Helper function to calculate the number of hex digits needed
// int	handle_pointer(t_format format_info, void *ptr)
// {
// 	uintptr_t	address;
// 	int			count;
// 	int			num_digits;
// 	int			padding;
// 	int			i;

// 	padding = format_info.width - num_digits;
// 	num_digits = calculate_hex_digits(address) + 2;
// 	count = 0;
// 	address = (uintptr_t)ptr;
// 	i = 0;
// 	if (!format_info.minus && padding > 0)
// 	{
// 		for (int i = 0; i < padding; i++)
// 			count += ft_putchar(' ');
// 	}
// 	count += ft_putstr("0x");
// 	if (address == 0)
// 	{
// 		if (format_info.precision == 0)
// 			return count;
// 		else
// 			count += ft_putchar('0');
// 	}
// 	else
// 		count += prt_hex(address, 0);
// 	if (format_info.minus && padding > 0)
// 	{
// 		for (int i = 0; i < padding; i++)
// 			count += ft_putchar(' ');
// 	}
// 	return (count);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:35:44 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:54:40 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	handle_null_string(char **string, t_format format_info, size_t *str_len)
{
	if (*string == NULL)
	{
		if (format_info.precision == 0)
			*str_len = 0;
		else
		{
			*string = "(null)";
			*str_len = ft_strlen(*string);
		}
	}
	else
		*str_len = ft_strlen(*string);
}

size_t	print_string(char *string, size_t print_len)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < print_len)
	{
		count += ft_putchar(string[i]);
		i++;
	}
	return (count);
}

int	handle_str(t_format format_info, va_list args)
{
	char	*string;
	size_t	count;
	size_t	str_len;
	size_t	print_len;
	size_t	padding;

	count = 0;
	string = va_arg(args, char *);
	handle_null_string(&string, format_info, &str_len);
	if (format_info.precision >= 0 && format_info.precision < (int)str_len)
		print_len = format_info.precision;
	else
		print_len = str_len;
	padding = calculate_padding(format_info, print_len);
	if (!format_info.minus)
		count += print_padding(padding);
	count += print_string(string, print_len);
	if (format_info.minus)
		count += print_padding(padding);
	return (count);
}

// string has to handle the following:
	// width, -, dot

// width: min chars to print, extra: spaces
// '-' : left justify. ('  Hi.' -> 'Hi.  ')
// '.' : precision. (max chars to print)
// width :  min chars to print
//  NOTE
	// 1. Width cant truncate a string but precision should
	// 2. Precision 0 should return an empty strring
	// 3. When there is string given as input it should return null
		// a) but a precision of 0 with it means we return empty string
		// b) otherwise we consider string as "(null)"

//X
//: Old versions of code (or) unused  code:
//X

// char	*ft_spaces(const char *str, size_t n, int minus)
// {
// 	char				*new_str;
// 	unsigned long		i;

// 	if (str == NULL)
// 		str = "(null)";
// 	new_str = malloc(ft_strlen(str) + n + 1);
// 	if (!new_str)
// 		return (NULL);
// 	if (minus)
// 	{
// 		ft_strcpy(new_str, str);
// 		i = ft_strlen(str);
// 		while (i < ft_strlen(str) + n)
// 			new_str[i++] = ' ';
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < n)
// 			new_str[i++] = ' ';
// 		ft_strcpy(new_str + n, str);
// 	}
// 	return (new_str[ft_strlen(str) + n] = '\0', new_str);
// }

// char	*handle_str_width(t_format format_info, char *string)
// {
// 	size_t	precision;
// 	size_t	width;
// 	int		minus;
// 	size_t	len;

// 	len = ft_strlen(string);
// 	precision = format_info.precision;
// 	width = format_info.width;
// 	minus = format_info.minus;
// 	if (width < precision && precision)
// 		width = precision;
// 	if (width)
// 		string = ft_spaces(string, width - len, minus);
// 	return (string);
// }

// int	handle_str(t_format format_info, va_list args)
// {
// 	char	*org_string;
// 	char	*string;
// 	int		count;

// 	count = 0;
// 	org_string = va_arg(args, char *);
// 	if (org_string == NULL)
// 		return (ft_putstr_fd("(null)", 1), ft_strlen("(null)"));
// 	string = ft_strdup(org_string);
// 	if (string == NULL)
// 		return (-1);
// 	if (format_info.precision > 0 && ft_strlen(string) > format_info.precision)
// 		string = ft_substr(string, 0, (format_info.precision));
// 	if (format_info.width > 0)
// 		string = handle_str_width(format_info, string);
// 	ft_putstr_fd(string, 1);
// 	count = ft_strlen(string);
// 	return (count);
// }

// int	handle_str(t_format format_info, va_list args)
// {
// 	char		*string;
// 	size_t		count;
// 	size_t		str_len;
// 	size_t		print_len;
// 	size_t		padding;
// 	size_t		i;

// 	i = 0;
// 	count = 0;
// 	padding = 0;
// 	string = va_arg(args, char *);
// 	if (string == NULL)
// 	{
// 		if (format_info.precision == 0)
// 			str_len = 0;
// 		else
// 		{
// 			string = "(null)";
// 			str_len = ft_strlen(string);
// 		}
// 	}
// 	else
// 		str_len = ft_strlen(string);
// 	print_len = str_len;
// 	if (format_info.precision >= 0 && format_info.precision < str_len)
// 		print_len = format_info.precision;
// 	if (format_info.width > print_len)
// 		padding = format_info.width - print_len;
// 	if (!format_info.minus)
// 	{
// 		while (i < padding)
// 		{
// 			count += ft_putchar(' ');
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (i < print_len)
// 	{
// 		count += ft_putchar(string[i]);
// 		i++;
// 	}
// 	i = 0;
// 	if (format_info.minus)
// 	{
// 		while (i < padding)
// 		{
// 			count += ft_putchar(' ');
// 			i++;
// 		}
// 	}
// 	return (count);
// }

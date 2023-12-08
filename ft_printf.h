/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:50:47 by sprodatu          #+#    #+#             */
/*   Updated: 2023/12/08 10:15:20 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	int			width;
	int			precision;
	int			minus;
	int			zero;
	int			dot;
	int			hash;
	int			space;
	int			plus;
	char		specifier;
}			t_format;

int			is_flag(char c);
t_format	parse_format(const char **current);
int			handle_format(t_format format_info, va_list args);
int			ft_printf(const char *str, ...);
int			handle_char(t_format format_info, va_list args);
int			ft_putchar(char c);
int			handle_str(t_format format_info, va_list args);
char		*ft_strcpy(char *dst, const char *src);
int			handle_percent(t_format format_info);
int			handle_int(t_format *f_info, int value);
size_t		print_padding(size_t padding);
size_t		zero_padding(size_t padding);
size_t		calculate_padding(t_format format_info, size_t print_len);
size_t		ft_putstr(char *s);
void		add_padding(char *str, int num_len, int precision, int is_neg);
int			handle_uint(t_format *f_info, unsigned int value);
char		*ft_utoa(unsigned int n);
int			handle_hexa(t_format f_info, unsigned int num);
int			handle_pointer(t_format format_info, void *ptr);
int			prnt_hexpad(int pad_len, char pad_char);
int			print_hex_prefix(char specifier);
int			put_hexa(unsigned int num, int case_type, t_format f_info);
int			print_hex(unsigned int num, int case_type, int num_digits);
int			prt_pad_n_prefix(t_format f_info, int *values);
int			print_hex_digit(unsigned int digit, int case_type);
void		handle_int_flags(t_format *format_info, int value,
				int *is_negative);
char		*apply_precision(char *value_str, int precision);
char		*handle_i_neg_n_min(int *value, int *is_neg);
int			print_int_padding(int pad_width, char pad_char);
int			calculate_hex_digits(uintptr_t num);
int			add_sign(t_format *f_info, int is_neg);

#endif

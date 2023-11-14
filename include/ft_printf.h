/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:50:47 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/14 07:30:58 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		width;
	int		precision;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	char	specifier;
}			t_format;

int			is_flag(char c);
t_format	parse_format(const char **current, va_list args);
int			handle_format(t_format format_info, va_list args);
int			ft_printf(const char *str, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:50:47 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/12 07:43:01 by sprodatu         ###   ########.fr       */
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
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	char	specifier;
}			t_format;

int		ft_printf(const char *str, ...);

#endif

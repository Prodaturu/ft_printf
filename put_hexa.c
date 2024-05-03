/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:00:17 by sprodatu          #+#    #+#             */
/*   Updated: 2024/05/03 21:55:46 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	cal_pad_len(unsigned int num, t_format f_info, int *values)
{
	values[0] = calculate_hex_digits(num);
	values[1] = 0;
	if (f_info.hash && num != 0)
		values[1] = 2;
	values[2] = 0;
	if (f_info.precision > values[0])
		values[2] = f_info.precision - values[0];
	values[3] = f_info.width - values[0] - values[2] - values[1];
	if (num == 0 && f_info.precision == 0)
	{
		values[0] = 0;
		values[3] = f_info.width;
	}
	return (0);
}

int	put_hexa(unsigned int num, int case_type, t_format f_info)
{
	int	count;
	int	values[4];

	count = 0;
	cal_pad_len(num, f_info, values);
	count += prt_pad_n_prefix(f_info, values);
	count += prnt_hexpad(values[2], '0');
	if (!(num == 0 && f_info.precision == 0))
		count += print_hex(num, case_type, values[0]);
	if (f_info.minus && values[3] > 0)
		count += prnt_hexpad(values[3], ' ');
	return (count);
}

// int	put_hexa(unsigned int num, int case_type, t_format f_info)
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

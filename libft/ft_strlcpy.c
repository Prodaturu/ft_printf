/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:28:27 by sprodatu          #+#    #+#             */
/*   Updated: 2024/04/24 15:58:29 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies a string from source to destination, up to a given size.
 *
 * @param dst The destination string.
 * @param src The source string.
 * @param dstsize The size of the destination buffer.
 * @return The total length of the source string.
 */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	char	*dst_ptr;
	char	*src_ptr;

	dst_ptr = (char *)dst;
	src_ptr = (char *)src;
	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (*src_ptr != '\0' && dstsize > 1)
	{
		*dst_ptr = *src_ptr;
		dst_ptr++;
		src_ptr++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst_ptr = '\0';
	return (src_length);
}

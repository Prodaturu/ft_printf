/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:32:34 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/14 05:35:33 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	count;

	count = ft_printf("Hello, World!\n");
	printf("Printed %d characters\n", count);
	count = ft_printf("This is a number: %d\n", 42);
	printf("Printed %d characters\n", count);
	count = ft_printf("Here's a string: %s\n", "Sample String");
	printf("Printed %d characters\n", count);
	return (0);
}

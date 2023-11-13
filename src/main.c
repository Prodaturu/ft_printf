/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:32:34 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/13 22:37:49 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int count;

	// Example usage of ft_printf
	count = ft_printf("Hello, World!\n");
	printf("Printed %d characters\n", count);
	count = ft_printf("This is a number: %d\n", 42);
	printf("Printed %d characters\n", count);
	count = ft_printf("Here's a string: %s\n", "Sample String");
	printf("Printed %d characters\n", count);
	return (0);
}

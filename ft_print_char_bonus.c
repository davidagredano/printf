/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:45 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/10 14:59:00 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	// print the char
	ft_putchar_fd((unsigned char) c, 1);

	// return the number of chars printed (always 1)
	return (1);
}

/*
 * The int argument is converted to an unsigned char, and the resulting
 * character is written.
 * Flags admitted: '-' left justification, field width.
 */
char	*printf_c(/*t_conv_spec *spec*/ size_t field_width, bool left_align, int c)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = 1;
	if (field_width > 1)
		size = field_width;

	i = size - 1;
	if (left_align)
		i = 0;

	// malloc a string of spaces
	str = calloc(size + 1, sizeof(char)); // ft_calloc
	if (!str)
		return (NULL);
	memset(str, ' ', size); // ft_memset

	str[i] = (unsigned char) c;

	return (str);
}

/*
 * Tests for the conversion specifier '%c'.
 * Flags admitted: '-' left justification, field width.
 */
void	c_tests(void)
{
	char c = 'A';
	printf("-Tests for conversion specifier %%c:\n\n");

	printf("%%c, c // No arguments\n");
	printf("|%c|\n", c);
	printf("|%s|\n", printf_c(0, false, c));

	printf("%%5c, c // Field width\n");
	printf("|%5c|\n", c);
	printf("|%s|\n", printf_c(5, false, c));

	printf("%%-5c, c // Field width + left justification\n");
	printf("|%-5c|\n", c);
	printf("|%s|\n", printf_c(5, true, c));

	printf("%%-c, c // Left justification without field width\n");
	printf("|%-c|\n", c);
	printf("|%s|\n", printf_c(0, true, c));

	printf("%%5.2c, c // Precision (ignored)\n");
	printf("|%5.2c|\n", c);

	printf("%%5.7c, c // Precision (ignored)\n");
	printf("|%5.7c|\n", c);

	// those are integration tests, not unit tests
	printf("%%--5c, c // Repeated flags (ignored)\n");
	printf("|%--5c|\n", c);
	printf("%%---5c, c // Repeated flags (ignored)\n");
	printf("|%--5c|\n", c);
	printf("%%c%%c, c // -Wformat-insufficient-args (ignored)\n");
	printf("|%c%c|\n", c);
	printf("%%c, c, c // -Wextra-args (ignored)\n");
	printf("|%c| \n", c, c);
}

int	main(void)
{
	c_tests();
}

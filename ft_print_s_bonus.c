/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:18:11 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/13 14:59:38 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(const char *s)
{
	if (s)
		return (ft_putstr(s));
	return (ft_putstr("(null)"));
}

/*
int	ft_print_str(const char *s)
{
	char	*str;
	int		ret;

	// alloc the string 
	if (!s)
		str = ft_calloc(7, sizeof(char)); // should output "(null)"
	else
		str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (-1);
	sprintf(str, "%s", s);

	// print the string and get the num of chars printed
	ret = ft_putstr(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}
 */

/*
 * The int argument is converted to an unsigned char, and the resulting
 * character is written.
 * Flags admitted: '-' left justification, field width.
char	*printf_s(t_conv_spec *spec bool left_align, size_t field_width, ssize_t precision, char *s)
{
	char	*str;
	ssize_t	i;

	// if no precision specified, precision = length of s
	if (precision == -1)
		precision = strlen(s); // ft_strlen

	// if no field_width specified, field_width = precision
	if (field_width < precision)
		field_width = precision;

	// malloc field_width bytes
	str = calloc(field_width + 1, sizeof(char)); // ft_calloc
	if (!str)
		return (NULL);
	memset(str, ' ', field_width); // ft_memset

	// copy s in memory
	// if left align: start copying s from i==0 to i==precision
	if (left_align)
	{
		i = 0;	
		while (i < precision)
		{
			str[i] = s[i];
			i++;
		}
	}
	// if not left align: copy right to left prom i==precision to i==0
	else
	{
		i = 0;
		while (i < precision)
		{
			str[field_width - 1 - i] = s[precision - 1 - i];
			i++;
		}
	}

	return (str);
}
 */

/*
 * Tests for the conversion specifier '%s'.
 * Flags admitted: '-' left justification, field width, '.' precision.
void	s_tests(void)
{
	char *s = "Hello";
	printf("-Tests for conversion specifier %%s:\n\n");

	printf("%%s, s // No arguments\n");
	printf("|%s|\n", s);
	printf("|%s|\n", printf_s(false, 0, -1, s));

	printf("%%10s, s // Field width\n");
	printf("|%10s|\n", s);
	printf("|%s|\n", printf_s(false, 10, -1, s));

	printf("%%-s, s // Left justification\n");
	printf("|%-s|\n", s);
	printf("|%s|\n", printf_s(true, 0, -1, s));

	printf("%%-10s, s // Left justification + Field width\n");
	printf("|%-10s|\n", s);
	printf("|%s|\n", printf_s(true, 10, -1, s));

	printf("%%9.4s, s // Field width > Precision\n");
	printf("|%9.4s|\n", s);
	printf("|%s|\n", printf_s(false, 9, 4, s));

	printf("%%-10.3s, s // Left justification + Field width > Precision\n");
	printf("|%-10.3s|\n", s);
	printf("|%s|\n", printf_s(true, 10, 3, s));

	printf("%%3.10s, s // Field width < Precision\n");
	printf("|%3.10s|\n", s);
	printf("|%s|\n", printf_s(false, 3, 10, s));
}
 */

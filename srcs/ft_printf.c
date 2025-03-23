/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/23 13:40:47 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int	print_format(t_spec *spec, va_list ap)
{
	if (spec->specifier == 'c')
		return (print_c(va_arg(ap, int), spec));
	else if (spec->specifier == 's')
		return (print_s(va_arg(ap, const char *), spec));
	else if (spec->specifier == 'p')
		return (print_p(va_arg(ap, void *), spec));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		return (print_d(va_arg(ap, int), spec));
	else if (spec->specifier == 'u')
		return (print_u(va_arg(ap, unsigned), spec));
	else if (spec->specifier == 'x' || spec->specifier == 'X')
		return (print_x(va_arg(ap, unsigned), spec));
	else if (spec->specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	print_format_str(char const *format, va_list ap, t_spec *spec)
{
	size_t	i;
	int		chars_printed;
	int		print_return;

	chars_printed = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && is_valid(&format[i + 1]))
		{
			i += 1 + parse(&format[i + 1], spec);
			print_return = print_format(spec, ap);
		}
		else
		{
			print_return = ft_putchar(format[i]);
		}
		if (print_return == -1)
			return (-1);
		chars_printed += print_return;
		i++;
	}
	return (chars_printed);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_spec	*spec;
	int		chars_printed;

	spec = ft_calloc(1, sizeof(t_spec));
	if (!spec)
		return (-1);
	va_start(ap, format);
	chars_printed = print_format_str(format, ap, spec);
	va_end(ap);
	free(spec);
	return (chars_printed);
}

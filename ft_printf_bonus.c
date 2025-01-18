/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/18 20:44:24 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_str(char const *str, va_list ap, t_spec *spec);
static int	ft_print_format(t_spec *spec, va_list ap);

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	t_spec	*spec;
	int		chars_printed;

	spec = ft_calloc(1, sizeof(t_spec));
	if (!spec)
		return (-1);
	va_start(ap, str);
	chars_printed = ft_print_str(str, ap, spec);
	va_end(ap);
	free(spec);
	return (chars_printed);
}

static int	ft_print_str(char const *str, va_list ap, t_spec *spec)
{
	size_t	i;
	int		chars_printed;
	int		print_return;

	chars_printed = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_isvalid(&str[i + 1]))
		{
			i += 1 + ft_parse(&str[i + 1], spec);
			print_return = ft_print_format(spec, ap);
		}
		else
		{
			print_return = ft_putchar(str[i]);
		}
		if (print_return == -1)
			return (-1);
		chars_printed += print_return;
		i++;
	}
	return (chars_printed);
}

static int	ft_print_format(t_spec *spec, va_list ap)
{
	if (spec->specifier == 'c')
		return (ft_print_c_bonus(va_arg(ap, int), spec));
	else if (spec->specifier == 's')
		return (ft_print_s_bonus(va_arg(ap, const char *), spec));
	else if (spec->specifier == 'p')
		return (ft_print_p_bonus(va_arg(ap, void *), spec));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		return (ft_print_di_bonus(va_arg(ap, int), spec));
	else if (spec->specifier == 'u')
		return (ft_print_u_bonus(va_arg(ap, unsigned), spec));
	else if (spec->specifier == 'x' || spec->specifier == 'X')
		return (ft_print_x_bonus(va_arg(ap, unsigned), spec));
	else if (spec->specifier == '%')
		return (ft_print_percent_bonus());
	return (0);
}

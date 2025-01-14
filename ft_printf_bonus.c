/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/13 20:19:05 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	ft_print_format(t_spec *spec, va_list ap);

/*
#include <stdio.h>
void	ft_debug_format_specification(t_spec *spec)
{
	printf("\e[33m");
	printf("specifier: %c\n", spec->specifier);
	printf("\e[0m");
}
*/

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	t_spec	*spec;
	size_t	i;
	int		chars_printed;

	spec = ft_calloc(1, sizeof(t_spec));
	if (!spec)
		return (0);
	va_start(ap, str);
	chars_printed = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_isvalid(&str[i + 1]))
		{
			spec->specifier = str[++i];
			chars_printed += ft_print_format(spec, ap);
		}
		else
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			chars_printed++;
		}
		i++;
	}
	va_end(ap);
	return (chars_printed);
}

static int	ft_print_format(t_spec *spec, va_list ap)
{
	if (spec->specifier == 'c')
		return (ft_print_c(va_arg(ap, int)));
	else if (spec->specifier == 's')
		return (ft_print_s(va_arg(ap, const char *)));
	else if (spec->specifier == 'p')
		return (ft_print_p(va_arg(ap, void *)));
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		return (ft_print_di(va_arg(ap, int)));
	else if (spec->specifier == 'u')
		return (ft_print_u(va_arg(ap, unsigned int)));
	else if (spec->specifier == 'x')
		return (ft_print_x(va_arg(ap, unsigned int)));
	else if (spec->specifier == 'X')
		return (ft_print_x_caps(va_arg(ap, unsigned int)));
	else if (spec->specifier == '%')
		return (ft_print_percent());
	return (0);
}

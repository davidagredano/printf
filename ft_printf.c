/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/11 13:11:20 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	ft_print_format(char specifier, va_list ap);

int	ft_printf(char const *str, ...)
{
	va_list	ap;
	size_t	i;
	int		chars_printed;

	va_start(ap, str);
	chars_printed = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			chars_printed += ft_print_format(str[i], ap);
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

static int	ft_print_format(char specifier, va_list ap)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_print_uint(va_arg(ap, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), false));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), true));
	else if (specifier == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(ap, const char *)));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(ap, void *)));
	else if (specifier == '%')
		return (ft_print_percent());
	return (0);
}

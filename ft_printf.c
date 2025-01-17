/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/17 17:00:41 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static bool	ft_isvalid_char(char specifier);
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
		if (str[i] == '%' && ft_isvalid_char(str[i + 1]))
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

static bool	ft_isvalid_char(char specifier)
{
	if (ft_strchr(CONVERSION_SPECIFIERS, specifier))
		return (true);
	return (false);
}

static int	ft_print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_print_c(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_s(va_arg(ap, const char *)));
	else if (specifier == 'p')
		return (ft_print_p(va_arg(ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_di(va_arg(ap, int)));
	else if (ft_strchr("uxX", specifier))
		return (ft_print_uint(va_arg(ap, unsigned), specifier));
	else if (specifier == '%')
		return (ft_print_percent());
	return (0);
}

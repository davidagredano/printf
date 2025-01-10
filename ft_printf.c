/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/10 10:37:15 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

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

int	ft_printf(char const *format, ...)
{
	char	*str;
	va_list	ap;
	size_t	i;
	int		ret;

	str = (char *) ft_calloc(BLOCK_SIZE, sizeof(char));
	va_start(ap, format);
	ret = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ret += ft_print_format(format[i], ap);
		}
		else
		{
			ft_putchar_fd(format[i], STDOUT_FILENO);
			ret++;
		}
		i++;
	}
	free(str);
	va_end(ap);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/09 18:50:10 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_printf(char const *format, ...)
{
	char 	*str;
	va_list	ap;
	size_t	i;

	str = (char *) ft_calloc(BLOCK_SIZE, sizeof(char));

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i')
				ft_print_int(va_arg(ap, int));
			else if (format[i] == 'u')
				ft_print_uint(va_arg(ap, unsigned int));
			else if (format[i] == 'x')
				ft_print_hex(va_arg(ap, unsigned int), false);
			else if (format[i] == 'X')
				ft_print_hex(va_arg(ap, unsigned int), true);
			else if (format[i] == 'c')
				ft_print_char(va_arg(ap, int));
			else if (format[i] == 's')
				ft_print_str(va_arg(ap, const char *));
			else if (format[i] == 'p')
				ft_print_ptr(va_arg(ap, void *));
			else if (format[i] == '%')
				ft_print_percent();
		}
		else
			ft_putchar_fd(format[i], STDOUT_FILENO);
		i++;
	}
	free(str);
	va_end(ap);
	return (1);
}

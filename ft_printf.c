/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/08 16:27:15 by dagredan         ###   ########.fr       */
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
			ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO); //TODO
		else
			ft_putchar_fd(format[i], STDOUT_FILENO);
		i++;
	}
	free(str);
	va_end(ap);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/17 20:41:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n, char specifier)
{
	char	*str;
	int		chars_printed;

	if (specifier == 'x')
		str = ft_uitoa(n, 16);
	else if (specifier == 'X')
		str = ft_uitoa_caps(n, 16);
	else
		str = ft_uitoa(n, 10);
	if (!str)
		return (0);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

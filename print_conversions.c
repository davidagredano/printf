/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:18:11 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/20 01:58:10 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(const char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	ft_print_ptr(void *p)
{
	char	*str;
	char	*nbr;
	int		chars_printed;

	if (!p)
		return (ft_putstr("(nil)"));
	nbr = ft_ultoa((unsigned long) p, 16);
	if (!nbr)
		return (-1);
	str = ft_strjoin("0x", nbr);
	if (!str)
	{
		free(nbr);
		return (-1);
	}
	chars_printed = ft_putstr(str);
	free(nbr);
	free(str);
	return (chars_printed);
}

int	ft_print_int(int n)
{
	char	*str;
	int		chars_printed;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

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
		return (-1);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

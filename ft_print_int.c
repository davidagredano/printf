/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:00 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/11 13:20:10 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	*str;
	int		chars_printed;

	str = ft_itoa(n);
	if (!str)
		return (0);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:33:53 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/11 12:59:33 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Writes a string to the standard output, 
 * without its terminating null byte ('\0').
 * Return the number of characters printed.
 */

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = (int) ft_strlen(str);
	write(STDOUT_FILENO, str, i);
	return (i);
}

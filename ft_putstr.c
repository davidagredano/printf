/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:33:53 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/12 11:35:43 by dagredan         ###   ########.fr       */
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
	if (!str)
		return (0);
	return ((int) write(STDOUT_FILENO, str, ft_strlen(str)));
}

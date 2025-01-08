/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:14:15 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/08 15:15:18 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_printf(char const *format, ...)
{
	char *str;

	str = (char *) ft_calloc(BLOCK_SIZE, sizeof(char));

	ft_strlcpy(str, format, BLOCK_SIZE);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
	return (1);
}

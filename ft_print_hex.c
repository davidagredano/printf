/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/09 12:15:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, bool upper)
{
	char	*str;
	int		ret;

	// alloc the unsigned int as ascii
	str = ft_calloc(16, sizeof(char)); 
	if (!str)
		return (-1);
	if (upper) 
		sprintf(str, "%X", n);
	else
		sprintf(str, "%x", n);

	// print the string
	ft_putstr_fd(str, STDOUT_FILENO);

	// get the num of chars printed
	ret = (int) ft_strlen(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/10 10:30:23 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	char	*str;
	int		ret;

	// alloc the pointer as hexadecimal ascii
	str = ft_calloc(32, sizeof(char)); 
	if (!str)
		return (-1);
	sprintf(str, "%p", ptr);

	// print the string and get the num of chars printed
	ret = ft_putstr(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

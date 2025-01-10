/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:12:43 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/10 10:31:43 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(unsigned int n)
{
	char	*str;
	int		ret;
	
	// alloc the uitoa
	str = ft_calloc(16, sizeof(char)); 
	if (!str)
		return (-1);
	sprintf(str, "%u", n);
	
	// print the string and get the num of chars printed
	ret = ft_putstr(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

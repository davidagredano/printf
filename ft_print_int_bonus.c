/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:00 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/10 10:27:16 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	char	*str;
	int		ret;
	
	// alloc the itoa
	str = ft_itoa(n);
	if (!str)
		return (-1);
	
	// print the string and get the num of chars printed
	ret = ft_putstr(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

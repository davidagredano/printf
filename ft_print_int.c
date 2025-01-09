/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:00 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/09 11:52:49 by dagredan         ###   ########.fr       */
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
	
	// print the string
	ft_putstr_fd(str, STDOUT_FILENO);

	// get the num of chars printed
	ret = (int) ft_strlen(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

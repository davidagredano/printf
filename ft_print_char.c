/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:45 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/09 15:51:29 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	char	*str;
	int		ret;

	// alloc the unsigned int as ascii
	str = ft_calloc(2, sizeof(char)); 
	if (!str)
		return (-1);
	str[0] = (unsigned char) c;

	// print the string
	ft_putstr_fd(str, STDOUT_FILENO);

	// get the num of chars printed
	ret = (int) ft_strlen(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

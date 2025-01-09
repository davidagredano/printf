/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:18:11 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/09 16:54:20 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *s)
{
	char	*str;
	int		ret;

	// alloc the string 
	if (!s)
		str = ft_calloc(7, sizeof(char)); // should output "(null)"
	else
		str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (-1);
	sprintf(str, "%s", s);

	// print the string
	ft_putstr_fd(str, STDOUT_FILENO);

	// get the num of chars printed
	ret = (int) ft_strlen(str);

	// free str
	free(str);

	// return the number of chars printed
	return (ret);
}

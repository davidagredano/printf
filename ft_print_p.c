/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/18 20:43:32 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_p(void *ptr)
{
	char	*str;
	char	*nbr;
	int		chars_printed;

	if (!ptr)
		return (ft_putstr("(nil)"));
	nbr = ft_ultoa((unsigned long) ptr, 16);
	if (!nbr)
		return (-1);
	str = ft_strjoin("0x", nbr);
	if (!str)
	{
		free(nbr);
		return (-1);
	}
	chars_printed = ft_putstr(str);
	free(nbr);
	free(str);
	return (chars_printed);
}

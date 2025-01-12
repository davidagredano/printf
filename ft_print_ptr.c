/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/12 13:46:19 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	char	*str;
	char	*nbr;
	int		ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	nbr = ft_ultoa((unsigned long) ptr, 16);
	if (!nbr)
		return (0);
	str = ft_strjoin("0x", nbr);
	if (!str)
	{
		free(nbr);
		return (0);
	}
	ret = ft_putstr(str);
	free(nbr);
	free(str);
	return (ret);
}

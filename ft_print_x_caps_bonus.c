/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_caps_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:43:16 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/13 14:23:50 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_caps(unsigned int n)
{
	char	*str;
	int		chars_printed;

	str = ft_uitoa_caps(n, 16);
	if (!str)
		return (0);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

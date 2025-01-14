/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:15:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/14 08:15:27 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	ft_isvalid(const char *specification)
{
	while (ft_strchr(FLAGS, *specification))
		specification++;
	while (ft_isdigit(*specification))
		specification++;
	if (*specification == '.')
		specification++;
	while (ft_isdigit(*specification))
		specification++;
	if (ft_strchr(CONVERSION_SPECIFIERS, *specification))
		return (true);
	return (false);
}

// Return the number of chars read
/*
int	ft_parse(const char *specification, t_spec *spec)
{
	int	chars_read;

	chars_read = 0; // TODO use the iterator because the arg is const
	return (chars_read);
}
*/

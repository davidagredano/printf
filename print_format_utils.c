/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:18:13 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/20 00:28:00 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/**
 * Allocates a string of the appropriate size.
 * Initializes all characters except for the terminating NUL character to ' ',
 * or '0' if the zero_padding flag is present.
 * Returns a pointer to the allocated string, or NULL if allocation fails.
 */
char	*ft_get_base_str(t_spec *spec)
{
	char	*str;

	str = ft_calloc(spec->field_width + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (spec->zero_padding)
		ft_memset(str, '0', spec->field_width);
	else
		ft_memset(str, ' ', spec->field_width);
	return (str);
}

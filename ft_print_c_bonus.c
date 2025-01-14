/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:45 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/14 16:56:18 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_base_str(t_spec *spec);
static void	ft_insert_char(int c, char *str, t_spec *spec);

/**
 * The int argument is converted to an unsigned char, and the resulting
 * character is written.
 * Flags admitted: left justification, field width.
 */
int	ft_print_c_bonus(int c, t_spec *spec)
{
	char	*str;
	int		chars_printed;

	str = ft_get_base_str(spec);
	if (!str)
		return (0);
	ft_insert_char(c, str, spec);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

/**
 * Allocates a string of the appropriate size.
 * Initializes all characters to ' ' except for the terminating NUL character.
 * Returns a pointer to the allocated string, or NULL if allocation fails.
 */
static char	*ft_get_base_str(t_spec *spec)
{
	char	*str;

	if (spec->field_width < 1)
		spec->field_width = 1;
	str = ft_calloc(spec->field_width + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, ' ', spec->field_width);
	return (str);
}

/**
 * Inserts the character to the correct position in the string.
 */
static void	ft_insert_char(int c, char *dest, t_spec *spec)
{
	if (spec->left_align)
		dest[0] = (unsigned char) c;
	else
		dest[spec->field_width - 1] = (unsigned char) c;
}

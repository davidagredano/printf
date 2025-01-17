/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:45 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/17 20:28:03 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_validate_spec(int c, t_spec *spec);
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

	ft_validate_spec(c, spec);
	str = ft_get_base_str(spec);
	if (!str)
		return (0);
	ft_insert_char(c, str, spec);
	ft_putstr(str);
	free(str);
	return (spec->field_width);
}

/**
 * Ensures that NUL character won't be inserted at the beginning of the str if
 * the left align flag is present. That would print an empty string as a result.
 * Ensures a minimum field width of 1 to copy the character.
 * Resets the rest of the unsupported flags.
 */
static void	ft_validate_spec(int c, t_spec *spec)
{
	spec->alternative_form = false;
	spec->zero_padding = false;
	if (c == '\0')
		spec->left_align = false;
	spec->leading_blank = false;
	spec->leading_sign = '\0';
	if (spec->field_width < 1)
		spec->field_width = 1;
	spec->precision = -1;
}

static char	*ft_get_base_str(t_spec *spec)
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

/**
 * Copies the character at the start or the end of the buffer pointed to by dst,
 * depending if the left align flag is present or not.
 */
static void	ft_insert_char(int c, char *dest, t_spec *spec)
{
	if (spec->left_align)
		dest[0] = (unsigned char) c;
	else
		dest[spec->field_width - 1] = (unsigned char) c;
}

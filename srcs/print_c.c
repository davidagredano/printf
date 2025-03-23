/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:49:45 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/23 13:40:52 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/**
 * Copies the character at the start or the end of the buffer pointed to by dst,
 * depending if the left align flag is present or not.
 */
static void	insert_char(int c, char *dest, t_spec *spec)
{
	if (spec->left_align)
		dest[0] = (unsigned char) c;
	else
		dest[spec->field_width - 1] = (unsigned char) c;
}

/**
 * Ensures that NUL character won't be inserted at the beginning of the str if
 * the left align flag is present. That would print an empty string as a result.
 * Ensures a minimum field width of 1 to copy the character.
 * Resets the rest of the unsupported flags.
 */
static void	validate_spec(int c, t_spec *spec)
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

/**
 * The int argument is converted to an unsigned char, and the resulting
 * character is written.
 * Flags admitted: left justification, field width.
 */
int	print_c(int c, t_spec *spec)
{
	char	*str;

	validate_spec(c, spec);
	str = get_base_str(spec);
	if (!str)
		return (-1);
	insert_char(c, str, spec);
	if (ft_putstr(str) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (spec->field_width);
}

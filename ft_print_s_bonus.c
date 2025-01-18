/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:18:11 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/18 15:58:31 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_validate_precision(const char *s, t_spec *spec);
static void	ft_validate_field_width(t_spec *spec);
static char	*ft_get_base_str(t_spec *spec);
static void	ft_insert_str(char *dst, const char *src, t_spec *spec);

/**
 * The characters of the string are written up to the NUL byte;
 * if a precision is specified, no more than the number specified are written.
 * Flags admitted: left justification, field width, precision.
 */
int	ft_print_s_bonus(const char *s, t_spec *spec)
{
	char	*str;
	int		chars_printed;

	if (!s && spec->precision > -1 && spec->precision < 6)
		s = "";
	else if (!s)
		s = "(null)";
	ft_validate_precision(s, spec);
	ft_validate_field_width(spec);
	str = ft_get_base_str(spec);
	if (!str)
		return (0);
	ft_insert_str(str, s, spec);
	chars_printed = ft_putstr(str);
	free(str);
	return (chars_printed);
}

/**
 * To comply with the spec:
 * If a precision is given, no NUL byte needs to be present;
 * if the precision is not specified, or is greater than the size of the string,
 * the string must contain a terminating NUL byte
 */
static void	ft_validate_precision(const char *s, t_spec *spec)
{
	if (spec->precision >= 0)
		spec->precision = ft_strnlen(s, spec->precision);
	else
		spec->precision = ft_strlen(s);
}

/**
 * Ensures that the field width won't cause truncation of the resulting string,
 * expanding its size to the number of characters that will be written.
 */
static void	ft_validate_field_width(t_spec *spec)
{
	if (spec->field_width < spec->precision)
		spec->field_width = spec->precision;
}

/**
 * Allocates a string of the appropriate size.
 * Initializes all characters to ' ' except for the terminating NUL character.
 * Returns a pointer to the allocated string, or NULL if allocation fails.
 */
static char	*ft_get_base_str(t_spec *spec)
{
	char	*str;

	str = ft_calloc(spec->field_width + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memset(str, ' ', spec->field_width);
	return (str);
}

/**
 * Copies the string src, properly aligned, to the buffer pointed to by dst.
 */
static void	ft_insert_str(char *dst, const char *src, t_spec *spec)
{
	int	i;

	i = 0;
	if (spec->left_align)
	{
		while (i < spec->precision)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		i = spec->field_width - spec->precision;
		ft_strlcpy(dst + i, src, spec->precision + 1);
	}
}

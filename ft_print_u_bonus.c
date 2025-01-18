/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:12:43 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/18 20:44:02 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_validate_spec(char *conv, t_spec *spec);
static char	*ft_get_base_str(t_spec *spec);
static void	ft_insert_conv(char *dst, const char *src, t_spec *spec);

/**
 * The unsigned int argument is converted to unsigned decimal notation.
 * The precision, if any, gives the minimum number of digits that must appear;
 * if the converted value requires fewer digits, it is padded on the left
 * with zeros.
 * When 0 is printed with an explicit precision 0, the output is empty.
 * Flags admitted: zero padding, left justification, field width, precision.
 */
int	ft_print_u_bonus(unsigned int n, t_spec *spec)
{
	char	*str;
	char	*conv;
	int		chars_printed;

	if (n == 0 && spec->precision == 0)
		conv = ft_strdup("");
	else
		conv = ft_uitoa(n, 10);
	if (!conv)
		return (-1);
	ft_validate_spec(conv, spec);
	str = ft_get_base_str(spec);
	if (!str)
	{
		free(conv);
		return (-1);
	}
	ft_insert_conv(str, conv, spec);
	chars_printed = ft_putstr(str);
	free(conv);
	free(str);
	return (chars_printed);
}

/**
 * Ignores '0' flag if left justification or precision is given.
 * Ensures a minimum precision and field width to avoid truncation.
 */
static void	ft_validate_spec(char *conv, t_spec *spec)
{
	if (spec->left_align || spec->precision >= 0)
		spec->zero_padding = false;
	if (spec->precision < (int) ft_strlen(conv))
		spec->precision = ft_strlen(conv);
	if (spec->field_width < spec->precision)
		spec->field_width = spec->precision;
}

/**
 * Allocates a string of the appropriate size.
 * Initializes all characters except for the terminating NUL character to ' ',
 * or '0' if the zero_padding flag is present.
 * Returns a pointer to the allocated string, or NULL if allocation fails.
 */
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
 * Copies the digits string, properly aligned, to the buffer pointed to by dst.
 * Adds zeros to the left of the converted value if there is room to fill in
 * the precision size.
 */
static void	ft_insert_conv(char *dst, const char *src, t_spec *spec)
{
	int	i;
	int	j;
	int	zeros;

	zeros = spec->precision - ft_strlen(src);
	i = 0;
	if (spec->left_align)
	{
		while (i < zeros)
			dst[i++] = '0';
		i = 0;
		while (zeros + i < spec->precision)
		{
			dst[zeros + i] = src[i];
			i++;
		}
	}
	else
	{
		i = 0;
		j = spec->field_width - spec->precision;
		while (i < zeros)
			dst[j + i++] = '0';
		ft_strlcpy(dst + i + j, src, ft_strlen(src) + 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/16 09:27:44 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_validate_spec(char *digits, t_spec *spec);
static char	*ft_get_base_str(t_spec *spec);
static void	ft_insert_digits(char *dst, const char *src, t_spec *spec);
static void	ft_insert_digits_ltr(char *dst, const char *src, t_spec *spec);
static void	ft_insert_digits_rtl(char *dst, const char *src, t_spec *spec);

/**
 * The unsigned int argument is converted to unsigned hexadecimal notation.
 * The letters abcdef are used for 'x' conversions;
 * the letters ABCDEF are used for 'X' conversions.
 * The precision, if any, gives the minimum number of digits that must appear;
 * if the converted value requires fewer digits, it is padded on the left
 * with zeros.
 * Flags admitted: alternative form, zero padding, left justification,
 * field width, precision.
 */
int	ft_print_x_bonus(unsigned int n, t_spec *spec)
{
	char	*str;
	char	*digits;
	int		chars_printed;

	digits = ft_uitoa(n, 16);
	if (!digits)
		return (0);
	ft_validate_spec(digits, spec);
	str = ft_get_base_str(spec);
	if (!str)
	{
		free(digits);
		return (0);
	}
	ft_insert_digits(str, digits, spec);
	chars_printed = ft_putstr(str);
	free(digits);
	free(str);
	return (chars_printed);
}

/**
 * Ignores '0' flag if left justification or precision is given.
 * Resets the unsupported ' ' and '+' flags.
 * Ensures a minimum precision and field width to avoid truncation,
 * adding extra space if '#' flag is present.
 */
static void	ft_validate_spec(char *digits, t_spec *spec)
{
	if (spec->left_align || spec->precision >= 0)
		spec->zero_padding = false;
	if (spec->leading_blank)
		spec->leading_blank = false;
	if (spec->leading_sign)
		spec->leading_sign = false;
	if (spec->precision < (int) ft_strlen(digits))
		spec->precision = ft_strlen(digits);
	if (spec->alternative_form)
		spec->precision += 2;
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
 * Calls one of the insertion functions depending on the left alignment flag.
 */
static void	ft_insert_digits(char *dst, const char *src, t_spec *spec)
{
	if (spec->left_align)
		ft_insert_digits_ltr(dst, src, spec);
	else
		ft_insert_digits_rtl(dst, src, spec);
}

/**
 * Copies the src string, from left to right, to the buffer pointed to by dst.
 * Prepends the string "0x" to src if the alternative form flag is present,
 * and adds '0' characters if there is room to fill in the precision size
 * before copying the src.
 */
static void	ft_insert_digits_ltr(char *dst, const char *src, t_spec *spec)
{
	int	i;
	int	lead_signs;

	lead_signs = spec->precision - ft_strlen(src);
	i = 0;
	if (spec->alternative_form)
		i += ft_strlcpy(dst, "0x", 3);
	ft_memset(dst + i, '0', lead_signs - i);
	i = 0;
	while (lead_signs + i < spec->precision)
	{
		dst[lead_signs + i] = src[i];
		i++;
	}
}

/**
 * Copies the src string, from right to left, to the buffer pointed to by dst.
 * Prepends the string "0x" to src if the alternative form flag is present,
 * and adds '0' characters if there is room to fill in the precision size
 * before copying the src.
 */
static void	ft_insert_digits_rtl(char *dst, const char *src, t_spec *spec)
{
	int	i;
	int	padding;
	int	lead_signs;

	padding = spec->field_width - spec->precision;
	lead_signs = spec->precision - ft_strlen(src);
	i = 0;
	if (spec->alternative_form)
		i += ft_strlcpy(dst + padding, "0x", 3);
	while (i < lead_signs)
	{
		dst[padding + i] = '0';
		i++;
	}
	ft_strlcpy(dst + padding + lead_signs, src, ft_strlen(src) + 1);
}

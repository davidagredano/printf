/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:59:51 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/17 10:44:44 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_validate_spec(char *digits, t_spec *spec);
static char	*ft_get_base_str(t_spec *spec);
static void	ft_insert_digits(char *dst, const char *src, t_spec *spec);
static void	ft_insert_digits_ltr(char *dst, const char *src, t_spec *spec);
static void	ft_insert_digits_rtl(char *dst, const char *src, t_spec *spec);

/**
 * The void * argument is converted to hexadecimal notation (as if by %#x).
 * Flags admitted: zero padding, left justification, leading blank,
 * leading sign, field width, precision.
 */
int	ft_print_p_bonus(void *p, t_spec *spec)
{
	char	*str;
	char	*conv;
	int		chars_printed;

	if (!p)
		conv = ft_strdup("(nil)");
	else
		conv = ft_ultoa((unsigned long) p, 16);
	if (!conv)
		return (0);
	ft_validate_spec(conv, spec);
	str = ft_get_base_str(spec);
	if (!str)
	{
		free(conv);
		return (0);
	}
	ft_insert_digits(str, conv, spec);
	chars_printed = ft_putstr(str);
	free(conv);
	free(str);
	return (chars_printed);
}

/**
 * Ensures alternative form flag.
 * Ignores '0' flag if left justification or precision is given.
 * Ignores ' ' if '+' is present.
 * Ensures a minimum precision and field width to avoid truncation,
 * adding extra space if ' ', '+' or '#' flags are present.
 * Finally, if the zero padding flag is still on, expands the precision
 * to the full field width to make room for the zeros.
 */
static void	ft_validate_spec(char *digits, t_spec *spec)
{
	spec->alternative_form = true;
	if (spec->left_align || spec->precision >= 0)
		spec->zero_padding = false;
	if (spec->leading_sign != '\0')
		spec->leading_blank = false;
	if (spec->precision < (int) ft_strlen(digits))
		spec->precision = ft_strlen(digits);
	if (spec->leading_sign != '\0' || spec->leading_blank)
		spec->precision += 1;
	if (spec->alternative_form)
		spec->precision += 2;
	if (spec->field_width < spec->precision)
		spec->field_width = spec->precision;
	if (spec->zero_padding)
		spec->precision = spec->field_width;
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
 * Prepends the character ' ', the character '+' and the string "0x" to src
 * if the correspondent flags are present; then adds '0' characters
 * if there is room to fill in the precision size before copying the src.
 */
static void	ft_insert_digits_ltr(char *dst, const char *src, t_spec *spec)
{
	int	i;
	int	lead_signs;

	lead_signs = spec->precision - ft_strlen(src);
	i = 0;
	if (spec->leading_blank)
		dst[i++] = ' ';
	if (spec->leading_sign != '\0')
		dst[i++] = spec->leading_sign;
	if (spec->alternative_form)
		i += ft_strlcpy(dst + i, "0x", 3);
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
 * Prepends the character ' ', the character '+' and the string "0x" to src
 * if the correspondent flags are present; then adds '0' characters
 * if there is room to fill in the precision size before copying the src.
 */
static void	ft_insert_digits_rtl(char *dst, const char *src, t_spec *spec)
{
	int	i;
	int	padding;
	int	lead_signs;

	padding = spec->field_width - spec->precision;
	lead_signs = spec->precision - ft_strlen(src);
	i = 0;
	if (spec->leading_blank)
		dst[padding + i++] = ' ';
	if (spec->leading_sign != '\0')
		dst[i++] = spec->leading_sign;
	if (spec->alternative_form)
		i += ft_strlcpy(dst + padding + i, "0x", 3);
	while (i < lead_signs)
	{
		dst[padding + i] = '0';
		i++;
	}
	ft_strlcpy(dst + padding + lead_signs, src, ft_strlen(src) + 1);
}

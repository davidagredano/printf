/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:36:00 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/20 00:22:22 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned	int	ft_validate_nbr(int n, t_spec *spec);
static void			ft_validate_spec(char *conv, t_spec *spec);
static void		ft_insert_conv(char *dst, const char *src, t_spec *spec);
static void		ft_insert_conv_ltr(char *dst, const char *src, t_spec *spec);
static void		ft_insert_conv_rtl(char *dst, const char *src, t_spec *spec);

/**
 * The int argument is converted to signed decimal notation.
 * The precision, if any, gives the minimum number of digits that must appear;
 * if the converted value requires fewer digits, it is padded on the left
 * with zeros.
 * When 0 is printed with an explicit precision 0, the output is empty.
 * Flags admitted: zero padding, left justification, leading blank, 
 * leading sign, field width, precision.
 */
int	ft_print_di_bonus(int n, t_spec *spec)
{
	unsigned int	u;
	char			*str;
	char			*conv;
	int				chars_printed;

	u = ft_validate_nbr(n, spec);
	if (n == 0 && spec->precision == 0)
		conv = ft_strdup("");
	else
		conv = ft_uitoa(u, 10);
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
 * Converts the integer to an unsigned integer.
 * If it is negative, extracts the sign to the spec struct.
 */
static unsigned int	ft_validate_nbr(int n, t_spec *spec)
{
	unsigned int	u;

	if (n < 0)
	{
		u = (unsigned) -n;
		spec->leading_sign = '-';
	}
	else
		u = (unsigned) n;
	return (u);
}

/**
 * Ensures alternative form flag.
 * Ignores '0' flag if left justification or precision is given.
 * Ignores ' ' if any leading sign is present.
 * Ensures a minimum precision and field width to avoid truncation,
 * adding extra space if leading blank or leading sign are present.
 * Finally, if the zero padding flag is still on, expands the precision
 * to the full field width to make room for the zeros.
 */
static void	ft_validate_spec(char *conv, t_spec *spec)
{
	spec->alternative_form = false;
	if (spec->left_align || spec->precision >= 0)
		spec->zero_padding = false;
	if (spec->leading_sign != '\0')
		spec->leading_blank = false;
	if (spec->precision < (int) ft_strlen(conv))
		spec->precision = ft_strlen(conv);
	if (spec->leading_blank || spec->leading_sign != '\0')
		spec->precision += 1;
	if (spec->field_width < spec->precision)
		spec->field_width = spec->precision;
	if (spec->zero_padding)
		spec->precision = spec->field_width;
}

static void	ft_insert_conv(char *dst, const char *src, t_spec *spec)
{
	if (spec->left_align)
		ft_insert_conv_ltr(dst, src, spec);
	else
		ft_insert_conv_rtl(dst, src, spec);
}

static void	ft_insert_conv_ltr(char *dst, const char *src, t_spec *spec)
{
	int	i;
	int	lead_signs;

	lead_signs = spec->precision - ft_strlen(src);
	i = 0;
	if (spec->leading_blank)
		dst[i++] = ' ';
	if (spec->leading_sign != '\0')
		dst[i++] = spec->leading_sign;
	ft_memset(dst + i, '0', lead_signs - i);
	i = 0;
	while (lead_signs + i < spec->precision)
	{
		dst[lead_signs + i] = src[i];
		i++;
	}
}

static void	ft_insert_conv_rtl(char *dst, const char *src, t_spec *spec)
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
		dst[padding + i++] = spec->leading_sign;
	while (i < lead_signs)
	{
		dst[padding + i] = '0';
		i++;
	}
	ft_strlcpy(dst + padding + lead_signs, src, ft_strlen(src) + 1);
}

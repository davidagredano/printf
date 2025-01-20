/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:12:43 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/20 01:39:48 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_validate_spec(char *conv, t_spec *spec);

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
 * Ignores not used flags.
 * Ignores '0' flag if left justification or precision is given.
 * Ensures a minimum precision and field width to avoid truncation.
 */
static void	ft_validate_spec(char *conv, t_spec *spec)
{
	spec->alternative_form = false;
	spec->leading_sign = '\0';
	spec->leading_blank = false;
	if (spec->left_align || spec->precision >= 0)
		spec->zero_padding = false;
	if (spec->precision < (int) ft_strlen(conv))
		spec->precision = ft_strlen(conv);
	if (spec->field_width < spec->precision)
		spec->field_width = spec->precision;
}

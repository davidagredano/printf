/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_parser_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:15:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/20 02:12:42 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_reset(t_spec *spec);
static int	ft_parse_flags(const char *spec_str, t_spec *spec);
static int	ft_parse_width_and_precision(const char *spec_str, t_spec *spec);

bool	ft_isvalid(const char *spec_str)
{
	while (ft_strchr(FLAGS, *spec_str))
		spec_str++;
	while (ft_isdigit(*spec_str))
		spec_str++;
	if (*spec_str == '.')
		spec_str++;
	while (ft_isdigit(*spec_str))
		spec_str++;
	if (ft_strchr(CONVERSION_SPECIFIERS, *spec_str))
		return (true);
	return (false);
}

int	ft_parse(const char *spec_str, t_spec *spec)
{
	int	i;

	ft_reset(spec);
	i = ft_parse_flags(spec_str, spec);
	i += ft_parse_width_and_precision(spec_str + i, spec);
	if (ft_strchr(CONVERSION_SPECIFIERS, spec_str[i]))
		spec->specifier = spec_str[i];
	return (i);
}

static void	ft_reset(t_spec *spec)
{
	spec->alternative_form = false;
	spec->zero_padding = false;
	spec->left_align = false;
	spec->leading_blank = false;
	spec->leading_sign = '\0';
	spec->field_width = 0;
	spec->precision = -1;
	spec->specifier = '\0';
}

static int	ft_parse_flags(const char *spec_str, t_spec *spec)
{
	int	i;

	i = 0;
	while (ft_strchr(FLAGS, spec_str[i]))
	{
		if (spec_str[i] == '#')
			spec->alternative_form = true;
		else if (spec_str[i] == '0')
			spec->zero_padding = true;
		else if (spec_str[i] == '-')
			spec->left_align = true;
		else if (spec_str[i] == ' ')
			spec->leading_blank = true;
		else if (spec_str[i] == '+')
			spec->leading_sign = '+';
		i++;
	}
	return (i);
}

static int	ft_parse_width_and_precision(const char *spec_str, t_spec *spec)
{
	int	i;

	i = 0;
	if (ft_isdigit(spec_str[i]))
		spec->field_width = ft_atoi(spec_str);
	while (ft_isdigit(spec_str[i]))
		i++;
	if (spec_str[i] == '.')
	{
		i++;
		spec->precision = ft_atoi(spec_str + i);
	}
	while (ft_isdigit(spec_str[i]))
		i++;
	return (i);
}

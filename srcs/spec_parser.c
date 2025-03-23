/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:15:36 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/23 13:41:26 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int	parse_width_and_precision(const char *spec_str, t_spec *spec)
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

static int	parse_flags(const char *spec_str, t_spec *spec)
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

static void	reset(t_spec *spec)
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

int	parse(const char *spec_str, t_spec *spec)
{
	int	i;

	reset(spec);
	i = parse_flags(spec_str, spec);
	i += parse_width_and_precision(spec_str + i, spec);
	if (ft_strchr(CONVERSION_SPECIFIERS, spec_str[i]))
		spec->specifier = spec_str[i];
	return (i);
}

bool	is_valid(const char *spec_str)
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

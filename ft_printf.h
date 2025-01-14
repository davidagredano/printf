/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/14 11:07:21 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION_SPECIFIERS "cspdiuxX%"
# define FLAGS "#0- +"

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

// Conversion specification
typedef struct s_spec
{
	bool	alternative_form;
	bool	zero_padding;
	bool	left_align;
	bool	leading_blank;
	bool	leading_sign;
	int		field_width;
	int		precision;
	char	specifier;
}		t_spec;

// Specification parser
bool	ft_isvalid(const char *spec_str);
int		ft_parse(const char *spec_str, t_spec *spec);

int		ft_printf(char const *str, ...);
int		ft_print_c(int c);
int		ft_print_s(const char *s);
int		ft_print_p(void *ptr);
int		ft_print_di(int n);
int		ft_print_u(unsigned int n);
int		ft_print_x(unsigned int n);
int		ft_print_x_caps(unsigned int n);
int		ft_print_percent(void);

#endif

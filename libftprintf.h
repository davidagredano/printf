/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/18 20:47:42 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define CONVERSION_SPECIFIERS "cspdiuxX%"
# define FLAGS "#0- +"

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_spec
{
	bool	alternative_form;
	bool	zero_padding;
	bool	left_align;
	bool	leading_blank;
	char	leading_sign;
	int		field_width;
	int		precision;
	char	specifier;
}		t_spec;

bool	ft_isvalid(const char *spec_str);
int		ft_parse(const char *spec_str, t_spec *spec);

int		ft_printf(char const *str, ...);
int		ft_print_c(int c);
int		ft_print_s(const char *s);
int		ft_print_p(void *ptr);
int		ft_print_di(int n);
int		ft_print_uint(unsigned int n, char specifier);

int		ft_print_c_bonus(int c, t_spec *spec);
int		ft_print_s_bonus(const char *s, t_spec *spec);
int		ft_print_p_bonus(void *p, t_spec *spec);
int		ft_print_di_bonus(int n, t_spec *spec);
int		ft_print_u_bonus(unsigned n, t_spec *spec);
int		ft_print_x_bonus(unsigned n, t_spec *spec);
int		ft_print_percent_bonus(void);

#endif

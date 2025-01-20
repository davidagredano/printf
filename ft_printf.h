/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/20 11:09:55 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
int		ft_print_str(const char *s);
int		ft_print_ptr(void *p);
int		ft_print_int(int n);
int		ft_print_uint(unsigned int n, char specifier);

char	*ft_get_base_str(t_spec *spec);
void	ft_insert_conv(char *dst, const char *src, t_spec *spec);

int		ft_print_c_bonus(int c, t_spec *spec);
int		ft_print_s_bonus(const char *s, t_spec *spec);
int		ft_print_p_bonus(void *p, t_spec *spec);
int		ft_print_d_bonus(int n, t_spec *spec);
int		ft_print_u_bonus(unsigned n, t_spec *spec);
int		ft_print_x_bonus(unsigned n, t_spec *spec);

#endif

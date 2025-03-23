/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/03/23 13:40:06 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION_SPECIFIERS "cspdiuxX%"
# define FLAGS "#0- +"

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

int		ft_printf(char const *str, ...);

bool	is_valid(const char *spec_str);
int		parse(const char *spec_str, t_spec *spec);

char	*get_base_str(t_spec *spec);
void	insert_conv(char *dst, const char *src, t_spec *spec);

int		print_c(int c, t_spec *spec);
int		print_s(const char *s, t_spec *spec);
int		print_p(void *p, t_spec *spec);
int		print_d(int n, t_spec *spec);
int		print_u(unsigned n, t_spec *spec);
int		print_x(unsigned n, t_spec *spec);

#endif

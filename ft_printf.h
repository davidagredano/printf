/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/13 15:49:05 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSION_SPECIFIERS "cspdiuxX%"

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_conv_spec
{
	bool	alternative_form;
	bool	zero_padding;
	bool	left_align;
	bool	leading_blank;
	bool	leading_sign;
	size_t	field_width;
	ssize_t	precision;
}	t_conv_spec;

int	ft_printf(char const *str, ...);
int	ft_print_c(int c);
int	ft_print_s(const char *s);
int	ft_print_p(void *ptr);
int	ft_print_di(int n);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned int n);
int	ft_print_x_caps(unsigned int n);
int	ft_print_percent(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/12 18:42:07 by dagredan         ###   ########.fr       */
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

int	ft_printf(char const *format, ...);
int	ft_print_int(int n);
int	ft_print_uint(unsigned int n);
int	ft_print_hex(unsigned int n);
int	ft_print_hex_caps(unsigned int n);
int	ft_print_ptr(void *ptr);
int	ft_print_char(int c);
int	ft_print_str(const char *s);
int	ft_print_percent(void);

int	ft_putstr(const char *str);

#endif

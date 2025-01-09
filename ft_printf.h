/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/09 16:26:49 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# define BLOCK_SIZE 4096

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

# include <stdio.h> // TODO
# include <string.h> // TODO
# include <bsd/string.h> // TODO

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
int	ft_print_int(int n); // for d, i
int	ft_print_uint(unsigned int n); // for u
int	ft_print_hex(unsigned int n, bool upper); // for x, X
int	ft_print_ptr(void *ptr); // for p
int	ft_print_char(int c); // for c
int	ft_print_str(const char *s); // for s
//int	ft_print_percent(void); // for %

#endif

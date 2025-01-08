/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagredan <dagredan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:39:52 by dagredan          #+#    #+#             */
/*   Updated: 2025/01/08 09:41:58 by dagredan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h> // TODO
#include <string.h> // TODO
#include <bsd/string.h> // TODO
#include <stdbool.h>
#include <stdlib.h>

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

#endif

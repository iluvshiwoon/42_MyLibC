/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_u_integer_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:33:56 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 06:01:06 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

size_t	u_integer_get_preffix_size(t_lexer_status *lexer_status,
		size_t *u_int_len, unsigned int u_int_value)
{
	size_t	prefix;

	prefix = 0;
	lexer_status->width_char = ' ';
	if (lexer_status->lexer_flags.zero && !lexer_status->precision.exist)
		lexer_status->width_char = '0';
	if (lexer_status->precision.exist
		&& (size_t)lexer_status->precision.value > *u_int_len)
		prefix += lexer_status->precision.value - *u_int_len;
	else if (lexer_status->precision.exist
		&& (size_t)lexer_status->precision.value == 0 && u_int_value == 0)
		*u_int_len = 0;
	return (prefix);
}

void	printf_fd_u_integer_write(t_lexer_status *lexer_status, char *u_int_str,
		size_t u_int_len)
{
	if (lexer_status->precision.exist
		&& (size_t)lexer_status->precision.value > u_int_len)
		printf_fd_width(lexer_status, lexer_status->precision.value - u_int_len,
			'0');
	printf_fd_write(lexer_status, u_int_str, u_int_len);
}

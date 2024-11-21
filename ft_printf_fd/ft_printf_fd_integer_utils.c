/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_integer_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:33:56 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 06:00:36 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	printf_fd_integer_prefix(t_lexer_status *lexer_status, int int_value)
{
	if (int_value >= 0 && lexer_status->width_char == '0')
	{
		if (lexer_status->lexer_flags.plus)
			printf_fd_write(lexer_status, "+", 1);
		else if (lexer_status->lexer_flags.space)
			printf_fd_write(lexer_status, " ", 1);
	}
	else if (int_value < 0 && lexer_status->width_char == '0')
		printf_fd_write(lexer_status, "-", 1);
}

size_t	integer_get_preffix_size(t_lexer_status *lexer_status, int int_value,
		size_t *int_len)
{
	size_t	prefix;

	prefix = 0;
	if (int_value < 0)
		prefix++;
	else if (lexer_status->lexer_flags.plus || lexer_status->lexer_flags.space)
		prefix++;
	if (lexer_status->lexer_flags.zero && !lexer_status->precision.exist)
		lexer_status->width_char = '0';
	else
		lexer_status->width_char = ' ';
	if (lexer_status->precision.exist
		&& (size_t)lexer_status->precision.value > *int_len)
		prefix += lexer_status->precision.value - *int_len;
	else if (lexer_status->precision.exist
		&& (size_t)lexer_status->precision.value == 0 && int_value == 0)
		*int_len = 0;
	return (prefix);
}

void	printf_fd_integer_write(t_lexer_status *lexer_status, void *arg,
		char *int_str, size_t int_len)
{
	if (lexer_status->width_char == ' ' && *((int *)arg) < 0)
		printf_fd_write(lexer_status, "-", 1);
	else if (lexer_status->width_char == ' ' && lexer_status->lexer_flags.plus)
		printf_fd_write(lexer_status, "+", 1);
	else if (lexer_status->width_char == ' ' && lexer_status->lexer_flags.space)
		printf_fd_write(lexer_status, " ", 1);
	if (lexer_status->precision.exist
		&& (size_t)lexer_status->precision.value > int_len)
		printf_fd_width(lexer_status, lexer_status->precision.value - int_len,
			'0');
	printf_fd_write(lexer_status, int_str, int_len);
}

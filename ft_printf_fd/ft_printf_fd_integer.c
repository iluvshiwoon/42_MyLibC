/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:32:01 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 06:00:59 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	lexer_integer(t_lexer_status *lexer_status, void *arg)
{
	size_t	int_len;
	char	*int_str;
	int		sign;

	sign = 1;
	int_len = 0;
	if (lexer_status->lexer_flags.hash)
		lexer_status->return_value = -1;
	if (*((int *)arg) == 0 && ++int_len)
		int_str = "0";
	else
	{
		if (*((int *)arg) < 0)
			sign = -1;
		printf_fd_utoa_size(sign * (*((int *)arg)), &int_len);
		int_str = malloc(sizeof(char) * (int_len));
		if (!int_str)
			return ;
		printf_fd_utoa(sign * (*((int *)arg)), lexer_status, int_str, int_len);
	}
	lexer_integer2(lexer_status, int_str, int_len, arg);
}

void	lexer_integer2(t_lexer_status *lexer_status, char *int_str,
		size_t int_len, void *arg)
{
	size_t	prefix;

	prefix = integer_get_preffix_size(lexer_status, (*((int *)arg)), &int_len);
	if (lexer_status->width)
	{
		if (lexer_status->lexer_flags.minus)
		{
			printf_fd_integer_write(lexer_status, arg, int_str, int_len);
			printf_fd_width(lexer_status, lexer_status->width - int_len
				- prefix, ' ');
		}
		if (!lexer_status->lexer_flags.minus)
		{
			printf_fd_integer_prefix(lexer_status, *((int *)arg));
			printf_fd_width(lexer_status, lexer_status->width - int_len
				- prefix, lexer_status->width_char);
			printf_fd_integer_write(lexer_status, arg, int_str, int_len);
		}
	}
	else
	{
		printf_fd_integer_prefix(lexer_status, *((int *)arg));
		printf_fd_integer_write(lexer_status, arg, int_str, int_len);
	}
	lexer_integer3(int_str, arg);
}

void	lexer_integer3(char *int_str, void *arg)
{
	if (*((int *)arg))
		free(int_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_u_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:32:01 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 06:01:04 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	lexer_u_integer(t_lexer_status *lexer_status, void *arg)
{
	size_t	u_int_len;
	char	*u_int_str;

	u_int_len = 0;
	if (lexer_status->lexer_flags.hash || lexer_status->lexer_flags.plus
		|| lexer_status->lexer_flags.space)
		lexer_status->return_value = -1;
	if (*((unsigned int *)arg) == 0 && ++u_int_len)
		u_int_str = "0";
	else
	{
		printf_fd_utoa_size((*((unsigned int *)arg)), &u_int_len);
		u_int_str = malloc(sizeof(char) * (u_int_len));
		if (!u_int_str)
			return ;
		printf_fd_utoa((*((unsigned int *)arg)), lexer_status, u_int_str,
			u_int_len);
	}
	lexer_u_integer2(lexer_status, u_int_str, u_int_len, arg);
}

void	lexer_u_integer2(t_lexer_status *lexer_status, char *u_int_str,
		size_t u_int_len, void *arg)
{
	size_t	prefix;

	prefix = u_integer_get_preffix_size(lexer_status, &u_int_len,
			*((unsigned int *)arg));
	if (lexer_status->width)
	{
		if (lexer_status->lexer_flags.minus)
		{
			printf_fd_u_integer_write(lexer_status, u_int_str, u_int_len);
			printf_fd_width(lexer_status, lexer_status->width - u_int_len - prefix,
				' ');
		}
		if (!lexer_status->lexer_flags.minus)
		{
			printf_fd_width(lexer_status, lexer_status->width - u_int_len - prefix,
				lexer_status->width_char);
			printf_fd_u_integer_write(lexer_status, u_int_str, u_int_len);
		}
	}
	else
		printf_fd_u_integer_write(lexer_status, u_int_str, u_int_len);
	lexer_u_integer3(u_int_str, arg);
}

void	lexer_u_integer3(char *u_int_str, void *arg)
{
	if (*((unsigned int *)arg))
		free(u_int_str);
}

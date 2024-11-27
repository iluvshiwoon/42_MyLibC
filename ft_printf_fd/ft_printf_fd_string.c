/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:28:47 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/27 14:56:36 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	lexer_putstr(t_lexer_status *lexer_status, void *arg)
{
	size_t	len;
	void	*arg_cpy;

	arg_cpy = arg;
	if (!arg)
		arg = "(null)";
	len = ft_strlen(arg);
	if (lexer_status->lexer_flags.hash || \
		lexer_status->lexer_flags.plus
		/*|| lexer_status->lexer_flags.space*/
		|| len > INT_MAX)
		lexer_status->return_value = -1;
	if (len > INT_MAX)
		return ;
	lexer_putstr2(lexer_status, arg, len, arg_cpy);
}

void	lexer_putstr2(t_lexer_status *lexer_status, void *arg, size_t len,
		void *arg_cpy)
{
	if (lexer_status->precision.exist
		&& lexer_status->precision.value < (int)len)
	{
		if (!arg_cpy)
			len = 0;
		else
			len = lexer_status->precision.value;
	}
	if (lexer_status->width)
	{
		if (lexer_status->lexer_flags.minus)
			printf_fd_write(lexer_status, arg, len);
		printf_fd_width(lexer_status, lexer_status->width - len, ' ');
		if (!lexer_status->lexer_flags.minus)
			printf_fd_write(lexer_status, arg, len);
	}
	else
		printf_fd_write(lexer_status, arg, len);
}

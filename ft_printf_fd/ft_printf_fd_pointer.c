/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:35:31 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 06:00:32 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	lexer_pointer(t_lexer_status *lexer_status, void *arg)
{
	size_t	ptr_len;
	char	*ptr_str;

	ptr_len = 0;
	if (lexer_status->lexer_flags.hash || lexer_status->lexer_flags.plus
		|| lexer_status->lexer_flags.zero || lexer_status->lexer_flags.space)
		lexer_status->return_value = -1;
	if (!arg)
	{
		ptr_str = "(nil)";
		ptr_len = 5;
	}
	else
	{
		printf_fd_pointer_size((uintptr_t)arg, &ptr_len);
		ptr_str = malloc(sizeof(char) * ptr_len);
		if (!ptr_str)
			return ;
		printf_fd_convert_pointer((uintptr_t)arg, lexer_status, ptr_str,
			ptr_len);
	}
	lexer_pointer2(lexer_status, ptr_str, ptr_len, arg);
}

void	lexer_pointer2(t_lexer_status *lexer_status, char *ptr_str,
		size_t ptr_len, void *arg)
{
	size_t	prefix;

	prefix = 0;
	if (arg)
		prefix = 2;
	if (lexer_status->width)
	{
		if (lexer_status->lexer_flags.minus)
			printf_fd_pointer_write(lexer_status, arg, ptr_str, ptr_len);
		printf_fd_width(lexer_status, lexer_status->width - ptr_len - prefix,
			' ');
		if (!lexer_status->lexer_flags.minus)
			printf_fd_pointer_write(lexer_status, arg, ptr_str, ptr_len);
	}
	else
		printf_fd_pointer_write(lexer_status, arg, ptr_str, ptr_len);
	if (arg)
		free(ptr_str);
}

void	printf_fd_pointer_write(t_lexer_status *lexer_status, void *arg,
		char *ptr_str, size_t ptr_len)
{
	if (arg)
		printf_fd_write(lexer_status, "0x", 2);
	printf_fd_write(lexer_status, ptr_str, ptr_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:19:15 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 20:07:10 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	ap;
	char	*current_char;
	int		return_value;

	return_value = 0;
	current_char = (char *)format;
	va_start(ap, format);
	return_value = lexer(fd, &current_char, ap);
	va_end(ap);
	return (return_value);
}

int	lexer(int fd, char **format, va_list ap)
{
	t_lexer_status	lexer_status;

	lexer_status.lexer_state = STRING_LITTERAL;
	lexer_status.printed_count = 0;
	lexer_status.return_value = 0;
	lexer_status.fd = fd;
	while (!iseof(*format, 0))
	{
		lexer_string_litteral(format, &lexer_status);
		lexer_flags(format, &lexer_status);
		lexer_width(format, &lexer_status);
		lexer_precision(format, &lexer_status);
		lexer_type(format, &lexer_status, ap);
	}
	if (lexer_status.return_value != -1)
		lexer_status.return_value = lexer_status.printed_count;
	return (lexer_status.return_value);
}

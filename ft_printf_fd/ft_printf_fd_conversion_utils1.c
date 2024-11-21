/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_conversion_utils1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:47:52 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 06:01:05 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

void	printf_fd_hex_size(unsigned int x, size_t *hex_len)
{
	if (x)
		printf_fd_hex_size(x / 16, hex_len);
	else
		return ;
	(*hex_len)++;
}

void	printf_fd_convert_hexa(unsigned int x, t_lexer_status *lexer_status,
		char *hex_address, size_t hex_len)
{
	char	*table;

	if (lexer_status->_case_ == LOWERCASE)
		table = "0123456789abcdef";
	else
		table = "0123456789ABCDEF";
	if (x)
		printf_fd_convert_hexa(x / 16, lexer_status, hex_address, --hex_len);
	else
		return ;
	hex_address[hex_len] = table[x % 16];
}

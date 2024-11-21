/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_lexer_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:25:53 by kgriset           #+#    #+#             */
/*   Updated: 2024/11/21 19:08:52 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

char	peek(char *format, size_t index)
{
	return (*(format + index));
}

unsigned int	iseof(char *format, size_t index)
{
	if (*(format + index) == 0)
		return (1);
	return (0);
}

char	consume(char **format, size_t index)
{
	char	char_to_return ;

	char_to_return = (*(*format + index));
	*format += (index + 1);
	return (char_to_return);
}

void	printf_fd_putchar(t_lexer_status *lexer_status, void *current_char)
{
	int	byte_read;

	byte_read = write(lexer_status->fd, current_char, 1);
	if (lexer_status->printed_count == INT_MAX || byte_read != 1)
		lexer_status->return_value = -1;
	lexer_status->printed_count++;
}

void	lexer_atoi(char **format, t_lexer_status *lexer_status, int *value,
		t_state_map state_map)
{
	char	current_char;

	while (lexer_status->lexer_state == state_map.current_state)
	{
		current_char = peek(*format, lexer_status->lexer_flags.i);
		if (ft_isdigit(current_char) && (((*value) == INT_MAX / 10
					&& current_char - '0' > 7) || ((*value) > INT_MAX / 10)))
		{
			(*value) = 0;
			lexer_status->lexer_state = state_map.next_state;
			lexer_status->return_value = -1;
			(lexer_status->lexer_flags.i)++;
		}
		else if (ft_isdigit(current_char))
		{
			(*value) = (*value) * 10 + current_char - '0';
			(lexer_status->lexer_flags.i)++;
		}
		else
			lexer_status->lexer_state = state_map.next_state;
	}
}

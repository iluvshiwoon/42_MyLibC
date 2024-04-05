/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:05:16 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:43:47 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void	*my_realloc(void *p_origin, size_t origin_size, size_t requested_size)
{
	void	*r_pointer;

	if (!requested_size)
		return (free(p_origin), NULL);
	else if (!p_origin)
		return (malloc(requested_size));
	else if (requested_size < origin_size)
	{
		r_pointer = malloc(requested_size);
		if (r_pointer)
			return (ft_memcpy(r_pointer, (const void *)p_origin,
					requested_size), free(p_origin), r_pointer);
	}
	else if (requested_size > origin_size)
	{
		r_pointer = malloc(requested_size);
		if (r_pointer)
			return (ft_memcpy(r_pointer, (const void *)p_origin, origin_size),
				free(p_origin), r_pointer);
	}
	else if (requested_size == origin_size)
		return (p_origin);
	return (NULL);
}

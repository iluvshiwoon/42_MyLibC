/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:51:37 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:43:50 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void	*vector_get(t_vector *v, size_t index)
{
	void	*data;

	data = NULL;
	if (v && index < v->vector_list.total)
		data = v->vector_list.items[index];
	return (data);
}

int	vector_set(t_vector *v, size_t index, void *item)
{
	int	status;

	status = ERROR;
	if (v && index < v->vector_list.total)
	{
		v->vector_list.items[index] = item;
		status = SUCCESS;
	}
	return (status);
}

int	vector_total(t_vector *v)
{
	int	data;

	data = ERROR;
	if (v)
		data = v->vector_list.total;
	return (data);
}

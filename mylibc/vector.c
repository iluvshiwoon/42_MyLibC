/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:18:30 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:54:14 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void	vector_init(t_vector *v)
{
	v->pf_vec_add = vector_add;
	v->pf_vec_delete = vector_delete;
	v->pf_vec_free = vector_free;
	v->pf_vec_get = vector_get;
	v->pf_vec_resize = vector_resize;
	v->pf_vec_set = vector_set;
	v->pf_vec_total = vector_total;
	v->vector_list.capacity = VECTOR_INIT_CAPACITY;
	v->vector_list.total = 0;
	v->vector_list.items = malloc(sizeof(void *) * v->vector_list.capacity);
}

int	vector_resize(t_vector *v, size_t capacity)
{
	int		status;
	void	**items;

	status = ERROR;
	if (v)
	{
		items = my_realloc(v->vector_list.items, sizeof(void *)
				* v->vector_list.capacity, sizeof(void *) * capacity);
		if (items)
		{
			v->vector_list.items = items;
			v->vector_list.capacity = capacity;
			status = SUCCESS;
		}
	}
	return (status);
}

int	vector_add(t_vector *v, void *item)
{
	int	status;

	status = ERROR;
	if (v)
	{
		if (v->vector_list.total == v->vector_list.capacity)
		{
			status = vector_resize(v, v->vector_list.capacity * 2);
			if (status == SUCCESS)
			{
				v->vector_list.items[v->vector_list.total++] = item;
			}
		}
		else
		{
			v->vector_list.items[v->vector_list.total++] = item;
			status = SUCCESS;
		}
	}
	return (status);
}

int	vector_delete(t_vector *v, size_t index)
{
	int	status;

	status = ERROR;
	if (v)
	{
		if (index >= v->vector_list.total)
			return (status);
		v->vector_list.items[index] = NULL;
		while (index < v->vector_list.total - 1)
		{
			v->vector_list.items[index] = v->vector_list.items[index + 1];
			++index;
		}
		v->vector_list.items[index] = NULL;
		v->vector_list.total--;
		if (v->vector_list.total == v->vector_list.capacity / 4)
			status = vector_resize(v, v->vector_list.capacity / 2);
		else
			status = SUCCESS;
	}
	return (status);
}

int	vector_free(t_vector *v)
{
	int	status;

	status = ERROR;
	if (v)
	{
		free(v->vector_list.items);
		v->vector_list.items = NULL;
		status = SUCCESS;
	}
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_double_link_list1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:16:08 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:46:02 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void	cdl_init_list(t_circular_db_ll *list)
{
	list->first_node = NULL;
	list->last_node = NULL;
	list->total = 0;
	list->pf_insert_end = cdl_insert_end;
	list->pf_delete_node = cdl_delete;
	list->pf_insert_after = cdl_insert_after;
	list->pf_insert_beginning = cdl_insert_beginning;
}

int	cdl_free_list(t_circular_db_ll *list)
{
	int					status;
	int					i;
	t_double_link_node	*node;

	status = ERROR;
	i = 0;
	if (list && list->first_node)
	{
		while (list->first_node != list->last_node || i == 0)
		{
			node = list->first_node;
			if (node)
				cdl_delete(list, node);
			else
				return (status);
			i = 1;
		}
		if (list->first_node)
		{
			node = list->first_node;
			cdl_delete(list, node);
			status = SUCCESS;
		}
	}
	return (status);
}

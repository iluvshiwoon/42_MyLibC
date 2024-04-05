/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:16:08 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:43:35 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void	init_list(t_double_link_list *list)
{
	list->first_node = NULL;
	list->last_node = NULL;
	list->pf_insert_end = insert_end;
	list->pf_delete_node = delete_node;
	list->pf_insert_after = insert_after;
	list->pf_insert_before = insert_before;
	list->pf_insert_beginning = insert_beginning;
}

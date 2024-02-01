/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_double_link_list1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:16:08 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/01 11:58:23 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void init_list(t_double_link_list * list)
{
    list->first_node = NULL;
    list->last_node = NULL;

    list->pf_insert_end = cdl_insert_end;
    list->pf_delete_node = cdl_delete_node;
    list->pf_insert_after = cdl_insert_after;
    list->pf_insert_beginning = cdl_insert_beginning;
}

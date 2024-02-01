/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_double_link_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:15:03 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/01 11:56:05 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

int pf_cdl_insert_after (t_circular_double_link_list * list, t_double_link_node * node, t_double_link_node * new_node)
{
    int status;

    status = ERROR;
    if (node && new_node)
    {
        new_node->previous = node;
        node->next->previous = new_node;
        new_node->next = node->next;
        node->next = new_node;
        status = SUCCESS;
    }
    return (status);
}

int pf_cdl_insert_beginning (t_circular_double_link_list * list, t_double_link_node * new_node)
{
    int status;

    status = ERROR;
    if (new_node)
    {
        if (list->first_node == NULL)
        {
            list->first_node = new_node;
            list->last_node = new_node;
            new_node->next = new_node;
            new_node->previous = new_node;
        }
        else
        {
            list->pf_insert_after(list->last_node, new_node);
            list->first_node = new_node;
        }
        status = SUCCESS;
    }
    return (status);
}

int pf_cdl_insert_end (t_circular_double_link_list * list, t_double_link_node * new_node)
{
    int status;

    status = ERROR;
    if (new_node)
    {
        if (list->last_node == NULL)
            list->pf_insert_beginning(list, new_node);
        else
        {
            list->pf_insert_after(list->last_node, new_node);
            list->last_node = new_node;
        }
        status = SUCCESS;
    }
    return (status);
}

int pf_cdl_delete (t_circular_double_link_list * list, t_double_link_node * node)
{
    int status;

    status = ERROR;
    if (node)
    {
        if (node->next == node)
        {
            list->last_node = NULL;
            list->first_node = NULL;
        }
        else 
        {
            if (node == list->first_node)
                list->first_node = node->next;
            else
                node->previous->next = node->next;
            if (node == list->last_node)
                list->last_node = node->previous;
            else
                node->next->previous = node->previous;
        }
        free(node->data);
        free(node);
        status = SUCCESS;
    }
    return (status);
}

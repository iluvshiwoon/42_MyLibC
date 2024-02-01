/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:15:03 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/01 11:55:36 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

int pf_insert_after (t_double_link_list * list, t_double_link_node * node, t_double_link_node * new_node)
{
    int status;

    status = ERROR;
    if (node && new_node)
    {
        new_node->previous = node;
        if (node->next == NULL)
            list->last_node = new_node;
        else
            node->next->previous = new_node;
        new_node->next = node->next;
        node->next = new_node;
        status = SUCCESS;
    }
    return (status);
}

int pf_insert_before (t_double_link_list * list, t_double_link_node * node, t_double_link_node * new_node)
{
    int status = ERROR;

    if (node && new_node)
    {
        new_node->next = node;
        if (node->previous == NULL)
            list->first_node = new_node;
        else
            node->previous->next = new_node;
        new_node->previous = node->previous;
        node->previous = new_node;
        status = SUCCESS;
    }
    return (status);
}
int pf_insert_beginning (t_double_link_list * list, t_double_link_node * new_node)
{
    int status;

    status = ERROR;
    if (new_node)
    {
        if (list->first_node == NULL)
        {
            list->first_node = new_node;
            list->last_node = new_node;
            new_node->next = NULL;
            new_node->previous = NULL;
        }
        else
            list->pf_insert_before(list, list->first_node, new_node);
        status = SUCCESS;
    }
    return (status);
}

int pf_insert_end (t_double_link_list * list, t_double_link_node * new_node)
{
    int status;

    status = ERROR;
    if (new_node)
    {
        if (list->last_node == NULL)
            list->pf_insert_beginning(list, new_node);
        else
            list->pf_insert_after(list, list->last_node, new_node);
        status = SUCCESS;
    }
    return (status);
}

int pf_delete (t_double_link_list * list, t_double_link_node * node)
{
    int status;

    status = ERROR;
    if (node)
    {
        if (node == list->first_node)
            list->first_node = node->next;
        else
            node->previous->next = node->next;
        if (node == list->last_node)
            list->last_node = node->previous;
        else
            node->next->previous = node->previous;
        free(node->data);
        free(node);
        status = SUCCESS;
    }
    return (status);
}

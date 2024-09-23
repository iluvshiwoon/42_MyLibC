/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:15:03 by kgriset           #+#    #+#             */
/*   Updated: 2024/09/23 23:03:39 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

int	ast_insert_after(t_ast_node *current_node\
                     , t_ast_node *new_node, t_direction direction)
{
	int	status;

	status = ERROR;
    if (new_node && current_node)
	{
		status = SUCCESS;
		if (direction == LEFT)
        {
            current_node->left = new_node;
            new_node->previous = current_node;
        }
		else
		{
            current_node->right = new_node;
            new_node->previous = current_node;
		}
	}
	return (status);
}

// int	ast_delete_node(t_ast *ast, t_ast_node *node)
// {
// 	int	status;
//
// 	status = ERROR;
// 	if (node)
// 	{
// 		if (node == ast->first_node)
// 			ast->first_node = node->right;
// 		else
// 			node->previous->right = node->right;
// 		if (node == ast->last_node)
// 		{
// 			ast->last_node = node->previous;
// 			node->previous->right = NULL;
// 		}
// 		else
// 			node->right->previous = node->previous;
// 		// free(node->data);
// 		free(node);
// 		status = SUCCESS;
// 	}
// 	return (status);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:15:03 by kgriset           #+#    #+#             */
/*   Updated: 2024/09/20 22:42:18 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

int	ast_insert_end(t_ast *ast, t_ast_node *new_node, t_direction direction)
{
	int	status;

	status = ERROR;
	if (new_node)
	{
		status = SUCCESS;
		if (ast->last_node == NULL )
		{
			ast->last_node = new_node;
			ast->first_node = new_node;
		}
		else if (direction == LEFT)
		{
			ast->last_node->left = new_node;
			return(status);
		}
		else
		{
			ast->last_node->right = new_node;
			ast->last_node = new_node;
		}
	}
	return (status);
}

int	ast_delete_node(t_ast *ast, t_ast_node *node)
{
	int	status;

	status = ERROR;
	if (node)
	{
		if (node == ast->first_node)
			ast->first_node = node->right;
		else
			node->previous->right = node->right;
		if (node == ast->last_node)
		{
			ast->last_node = node->previous;
			node->previous->right = NULL;
		}
		else
			node->right->previous = node->previous;
		// free(node->data);
		free(node);
		status = SUCCESS;
	}
	return (status);
}

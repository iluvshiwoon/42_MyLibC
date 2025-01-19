/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:11:25 by kgriset           #+#    #+#             */
/*   Updated: 2025/01/19 21:18:25 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc_local.h"

void	init_link_list(t_link_list *list)
{
	list->first_node = NULL;
    list->pf_lstadd_back = ft_lstadd_back;
    list->pf_lstadd_front = ft_lstadd_front;
    list->pf_lstclear = ft_lstclear;
    list->pf_lstiter = ft_lstiter;
    list->pf_lstsize = ft_lstsize;
    list->pf_lstlast = ft_lstlast;
}

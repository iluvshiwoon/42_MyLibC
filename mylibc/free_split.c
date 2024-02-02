/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:31:09 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/02 16:34:51 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mylibc_local.h"

int free_split(char ** split)
{
    size_t i;

    i = 0;
    if (split)
    {
        while (split[i])
        {
            if (!split[i])
                return (ERROR);
            free(split[i]);
            ++i;
        }
        free(split);
    }
    else
        return (ERROR);
    return (SUCCESS);
}

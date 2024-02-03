/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:00:34 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/03 10:40:24 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mylibc_local.h"

int array_in_place_reverse(int * array, size_t end)
{
    size_t i;
    int temp;

    i = 0;
    if (array && end > 0)
    {
        while (i <= (end - 2)/2 && end - i > 0) 
        {
            temp = array[end - 1 - i];
            array[end - 1 - i] = array[i];
            array [i] =  temp;
            i++;
        }
    }
    else
        return (ERROR);
    return (SUCCESS);
}

int array_rotate(int * array, size_t amount, size_t end)// rot 1 left == rot 3 right hence rot left = range - rot right
{
    if (array && end > 0 && array_in_place_reverse(array, end) &&
        array_in_place_reverse(array, amount) && array_in_place_reverse(array + amount, end - amount))
        return (SUCCESS);
    return (ERROR);
}

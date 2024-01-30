/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:49:14 by kgriset           #+#    #+#             */
/*   Updated: 2024/01/30 14:52:52 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibc.h"

int	*ft_atoi_safe(char *string)
{
    size_t i;
    int * r_value;
    int value;
    int is_digit;

    i = 0;
    is_digit = 0;
    value = 0;
	while (string[i])
	{
        is_digit = ft_isdigit(string[i]);
        if (is_digit && value >= INT_MAX / 10 && string[i]
			- '0' >= 8)
            return (NULL);
        else if (is_digit)
			value = value * 10 + string[i] - '0';
        else
            return (NULL);
	}
    r_value = malloc(sizeof(value));
    if (r_value)
        *r_value = value;
    return (r_value);
}

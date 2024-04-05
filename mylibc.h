/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:41:11 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:42:46 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBC_H
# define MYLIBC_H

// mylibc
# include "mylibc/mylibc_local.h"

// ft_printf project
int		ft_printf(const char *format, ...);

// get_next_line project
char	*get_next_line(int fd);

#endif

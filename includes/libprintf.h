/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 22:54:06 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/14 23:27:47 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

#define conversions (sSpdDioOuUxXcCeE, fF, gG, aA, n)

int         ft_printf(const char *restrict format, ...);
void        ft_print_var(va_list ap, char *c);
#endif

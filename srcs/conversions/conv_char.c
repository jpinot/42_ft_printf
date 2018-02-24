/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:01:06 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/21 16:06:47 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		conv_char(va_list ap, t_arg *arg, char *f)
{
	char	c;

	c = va_arg(ap, int);
	ft_putstr_fd(f, arg->fd);
	return (ft_printf_putchar(c, arg));
}

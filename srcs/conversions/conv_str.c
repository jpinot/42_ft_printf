/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:29:06 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/16 20:12:27 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		conv_str(va_list ap, t_arg *arg, char *f)
{
	char	*s;

	s = va_arg(ap, char *);
	if (arg->precision < 0)
		arg->precision *= -1;
	ft_putstr_fd(f, arg->fd);
	if (s == NULL)
		return (ft_printf_putstr("(null)", arg));
	return (ft_printf_putstr(s, arg));
}

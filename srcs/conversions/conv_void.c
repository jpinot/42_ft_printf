/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_void.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 19:00:27 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/20 19:58:44 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int				conv_void(va_list ap, t_arg *arg, int conv, char *f)
{
	void	*num;

	if (arg->precision)
		arg->pad_zero = 0;
	num = va_arg(ap, void *);
	arg->prefix = 120;
	ft_putstr_fd(f, arg->fd);
	return (ft_printf_putuint((uintmax_t)num, arg, conv));
}

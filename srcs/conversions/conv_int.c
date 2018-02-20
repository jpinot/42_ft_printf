/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:52:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/16 20:10:53 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static intmax_t	ft_int_check_length(intmax_t num, t_arg *arg)
{
	if (arg->lenght == 104104)
		num = (char)num;
	else if (arg->lenght == 108108)
		num = (long long)num;
	else if (arg->lenght == 104)
		num = (short)num;
	else if (arg->lenght == 108)
		num = (long)num;
	else if (arg->lenght == 122)
		num = (size_t)num;
	else if (arg->lenght == 116)
		num = (ptrdiff_t)num;
	else if (arg->lenght == 106)
		num = (intmax_t)num;
	else if (arg->lenght == 0)
		num = (int)num;
	return (num);
}

int				conv_int(va_list ap, t_arg *arg, int conv, char *f)
{
	intmax_t	num;
	t_arg		tmp;

	if (arg->p_switch && arg->precision >= 0)
		arg->pad_zero = 0;
	num = va_arg(ap, intmax_t);
	if (conv != 'D')
		num = ft_int_check_length(num, arg);
	if (arg->force_positive == 1 && num >= 0)
		arg->force_positive = 43;
	if (num < 0)
	{
		arg->force_positive = 45;
		num = -(num);
	}
	tmp = *arg;
	ft_putstr_fd(f, arg->fd);
	return (ft_printf_putint(num, &tmp));
}

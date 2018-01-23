/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:52:39 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/22 18:43:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static void	ft_int_check_length(intmax_t num, t_arg *arg)
{
	if (arg->lenght == 104104)
		num = (char)num;
	if (arg->lenght == 108108)
		num = (long long)num;
	if (arg->lenght == 104)
		num = (short)num;
	if (arg->lenght == 108)
		num = (long)num;
//	if (arg->lenght == 106)
//		num = (intmax_t)num;
	if (arg->lenght == 122)
		num = (size_t)num;
	if (arg->lenght == 116)
		num = (ptrdiff_t)num;
//	if (arg->lenght == 76)
//		num = (long double)num;
	else
		num = (int)num;
}

int			conv_int(va_list ap, t_arg *arg)
{
	intmax_t	num;
	t_arg		tmp;

	if (arg->precision)
		arg->pad_zero = 0;
	num = va_arg(ap, intmax_t);
	if (arg->force_positive == 1 || num < 0)
	{
		if (arg->force_positive && num >= 0)
			arg->force_positive = 43;
		if (num < 0)
		{
			arg->force_positive = 45;
			num = -(num);
		}
	}
	tmp = *arg;
	ft_int_check_length(num, arg);
	return(ft_printf_putint(num, &tmp));
}

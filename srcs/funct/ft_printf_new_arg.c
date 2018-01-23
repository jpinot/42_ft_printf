/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_new_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:47:19 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/22 14:22:31 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

t_arg	ft_printf_new_arg(t_arg *arg)
{
	arg->left_justify = 0;
	arg->force_positive = 0;
	arg->prefix = 0;
	arg->pad_zero = 0;
	arg->thousands_group = 0;
	arg->filed_width = 0;
	arg->precision = 0;
	arg->lenght = 0;
	return (*arg);
}

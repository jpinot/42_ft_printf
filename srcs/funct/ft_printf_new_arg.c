/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_new_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 10:47:19 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/23 15:42:02 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

t_arg	ft_printf_new_arg(t_arg *arg)
{
	arg->fd = 1;
	arg->left_justify = 0;
	arg->force_positive = 0;
	arg->prefix = 0;
	arg->pad_zero = 0;
	arg->filed_width = 0;
	arg->precision = 0;
	arg->lenght = 0;
	arg->p_switch = 0;
	return (*arg);
}

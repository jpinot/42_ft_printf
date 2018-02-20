/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pututf_8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/16 17:26:48 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_putchar(char c, t_arg *arg)
{
	int cnt;

	cnt = 0;
	arg->filed_width -= 1;
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0 && arg->pad_zero > 0)
			cnt += ft_pf_write_until('0', arg->filed_width, arg->fd);
		else if (arg->filed_width > 0)
			cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
		cnt += ft_pf_putchar(c, arg->fd);
	}
	else
	{
		cnt += ft_pf_putchar(c, arg->fd);
		if (arg->filed_width > 0)
			cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
	}
	return (cnt);
}

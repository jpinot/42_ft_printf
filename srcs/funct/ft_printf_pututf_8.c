/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pututf_8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/25 10:20:59 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_pututf_8(char *c, t_arg *arg)
{
		arg->filed_width -= 1;
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
			ft_putstr(c);
	}
	else
	{
			ft_putstr(c);
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pututf_8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/16 15:45:29 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_pututf_8(char *c, t_arg *arg)
{
	int	cnt;

	cnt = 0;
	if (c[0] == 0)
		cnt += 1;
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0)
			cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
		cnt += ft_pf_putstr(c, arg->fd);
	}
	else
	{
		cnt += ft_pf_putstr(c, arg->fd);
		if (arg->filed_width > 0)
			cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
	}
	free(c);
	return (cnt);
}

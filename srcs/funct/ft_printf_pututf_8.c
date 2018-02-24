/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pututf_8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:29:15 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/21 15:31:19 by jpinyot          ###   ########.fr       */
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
		cnt += write(arg->fd, c, ft_strlen(c));
	}
	else
	{
		cnt += write(arg->fd, c, ft_strlen(c));
		if (arg->filed_width > 0)
			cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
	}
	ft_strdel(&c);
	return (cnt);
}

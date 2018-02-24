/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_utf_8.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:21:48 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/21 13:30:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_left_justify(char *c, t_arg *arg)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	cnt += write(arg->fd, c, ft_strlen(c));
	if (arg->filed_width > 0 && arg->pad_zero == 0)
		cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
	return (cnt);
}

static int	ft_non_justify(char *c, t_arg *arg)
{
	int		cnt;
	int		i;

	cnt = 0;
	i = 0;
	if (arg->filed_width > 0 && arg->pad_zero)
		cnt += ft_pf_write_until('0', arg->filed_width, arg->fd);
	if (arg->filed_width > 0 && arg->pad_zero == 0)
		cnt += ft_pf_write_until(' ', arg->filed_width, arg->fd);
	cnt += write(arg->fd, c, ft_strlen(c));
	return (cnt);
}

int			ft_printf_putstr_utf_8(char *c, t_arg *arg)
{
	int cnt;

	cnt = 0;
	if (arg->left_justify == 0)
		cnt = ft_non_justify(c, arg);
	else
		cnt = ft_left_justify(c, arg);
	ft_strdel(&c);
	return (cnt);
}

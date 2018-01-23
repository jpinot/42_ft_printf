/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:46:22 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/22 15:57:09 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_putstr(char *s, t_arg *arg)
{
		arg->filed_width -= ft_strlen(s);
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
		ft_putstr(s);
	}
	else
	{
		ft_putstr(s);
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
	}
	return (0);
}

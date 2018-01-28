/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr_utf_8.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:21:48 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/25 13:44:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_putstr_utf_8(char **c, t_arg *arg)
{
		arg->filed_width -= 1;
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
		while (*c)
		{
			ft_putstr(*c);
			c++;
		}
	}
	else
	{
		while (*c)
		{
			ft_putstr(*c);
			c++;
		}
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
	}
	return (0);
}

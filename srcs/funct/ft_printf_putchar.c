/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:11:55 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/22 15:56:41 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			ft_printf_putchar(char c, t_arg *arg)
{
		arg->filed_width -= 1;
	if (arg->left_justify == 0)
	{
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		if (arg->filed_width > 0)
			ft_write(' ', arg->filed_width);
	}
	return (0);
}

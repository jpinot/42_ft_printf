/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utf_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:10:30 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/03 18:04:35 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			conv_utf_8(va_list ap, t_arg *arg)
{
	int		c;
	char	*a;

	a = NULL;
	c = va_arg(ap, int);
	a = ft_printf_from_int_to_utf_8(c, arg);
	return (ft_printf_pututf_8(a, arg));
}

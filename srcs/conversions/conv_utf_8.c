/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utf_8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:10:30 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/21 16:14:06 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			conv_utf_8(va_list ap, t_arg *arg, char *f)
{
	int		c;
	char	*a;

	a = NULL;
	if ((c = va_arg(ap, wchar_t)) < 0 ||
			(c >= 0xd800 && c < 0xe000) || c > 0x81000)
		return (-1);
	ft_putstr_fd(f, arg->fd);
	if (c == 0)
		return (ft_printf_putchar(0, arg));
	a = ft_printf_from_int_to_utf_8(c, arg);
	return (ft_printf_pututf_8(a, arg));
}

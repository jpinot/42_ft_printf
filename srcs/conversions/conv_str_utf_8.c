/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_utf_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:42:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/20 16:41:42 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int		ft_nbrlen(int *nbr)
{
	int *n;
	int cnt;

	n = nbr;
	cnt = 0;
	while (*n)
	{
		if (*n <= 127)
			cnt += 1;
		else if (*n >= 128 && *n <= 2047)
			cnt += 2;
		else if (*n >= 2048 && *n <= 65534)
			cnt += 3;
		else if (*n >= 65535 && *n <= 2097150)
			cnt += 4;
		n++;
	}
	return (cnt);
}

static int		ft_check_n(int nbr)
{
	int n;
	int cnt;

	n = nbr;
	cnt = 0;
	if (n <= 127)
		cnt += 1;
	else if (n >= 128 && n <= 2047)
		cnt += 2;
	else if (n >= 2048 && n <= 65534)
		cnt += 3;
	else if (n >= 65535 && n <= 2097150)
		cnt += 4;
	return (cnt);
}

static int		ft_check_correct_arg(int *s)
{
	int i;

	i = 0;
	while (s[i++])
	{
		if (s[i] < 0 || (s[i] >= 0xd800 && s[i] < 0xe000) || s[i] > 0x81000)
			return (-1);
	}
	return (0);
}

int				conv_str_utf_8(va_list ap, t_arg *arg, char *f)
{
	int		*s;
	char	*a;
	char	*x;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = va_arg(ap, int *);
	ft_putstr_fd(f, arg->fd);
	if (ft_check_correct_arg(s) == -1)
		return (-1);
	if (s == NULL)
		return (ft_printf_putstr("(null)", arg));
	if (arg->p_switch == 0)
		arg->precision = ft_nbrlen(s);
	if (s && ft_check_n(*s) <= arg->precision)
	{
		a = ft_printf_from_int_to_utf_8(*s, arg);
		s++;
	}
	else
//	if (arg->p_switch && arg->precision == 0)
		return (ft_printf_putstr("", arg));
	while (s[i])
	{
		x = a;
		if ((j = ft_strlen(a)) + ft_check_n(s[i]) <= arg->precision)
		{
			a = ft_strjoin(a, ft_printf_from_int_to_utf_8(s[i], arg));
			ft_strdel(&x);
		}
		else
			break;
		i++;
	}
//	if (arg->p_switch && arg->precision > 0)
//		arg->filed_width -= ft_strlen(a);
	return(ft_printf_putstr_utf_8(a, arg));
}

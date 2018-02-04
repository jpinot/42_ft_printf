/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_utf_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:42:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/04 23:25:50 by jpinyot          ###   ########.fr       */
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

static t_arg	*ft_check_width(t_arg *arg, char **s, int w)
{
	int i;
	int p;

	i = 0;
	p = arg->precision;
	while (s[i] && p--)
	{
		w -= ft_strlen(s[i]);
		i++;
	}
	arg->filed_width = w;
	return (arg);
}

int				conv_str_utf_8(va_list ap, t_arg *arg)
{
	int		*s;
	char	**a;
	int		i;
	int		j;
	int		width;

	s = va_arg(ap, int *);
	if (arg->p_switch == 0)
		arg->precision = ft_nbrlen(s);
//	ft_putnbr(arg->precision);
	a = (char **)malloc(sizeof(char *) * arg->precision + 1);
	a[arg->precision + 1] = NULL;
	i = 0;
	j = 0;
	width = arg->filed_width;
	if (arg->p_switch && arg->precision == 0)
		return (ft_printf_putstr("", arg));
	while (s[i] && j < arg->precision)
	{
		a[i] = ft_printf_from_int_to_utf_8(s[i], arg);
		j += ft_strlen(a[i]);
		i++;
	}
	a[i] = NULL;
	if (arg->p_switch && arg->precision > 0)
		arg = ft_check_width(arg, a, width);
	else
		arg->precision = i;
	return (ft_printf_putstr_utf_8(a, arg));
}

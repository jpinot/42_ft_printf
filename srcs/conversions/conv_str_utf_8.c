/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str_utf_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:42:01 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/25 13:44:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int		ft_nbrlen(int *nbr)
{
	int i;

	i = 0;
	while(nbr[i])
		i++;
	return (i);
}

static t_arg	*ft_check_width(t_arg *arg, char **s)
{
	int i;
	int cnt;
	
	i = 0;
	cnt = 0;
	while(s[i])
	{
		cnt += ft_strlen(s[i]);
		i++;
	}
	arg->filed_width -= cnt - 1;
	return (arg);
}

int				conv_str_utf_8(va_list ap, t_arg *arg)
{
	int		*s;
	char	**a;
	int		i;
	int		j;

	a = (char **)malloc(sizeof(char **) * 1);
	s = va_arg(ap, int *);
	j = ft_nbrlen(s);
	i = 0;
	while (i < j)
	{
		a[i] = ft_printf_from_int_to_utf_8(s[i]);
		i++;
	}
	a[i] = NULL;
	if (arg->filed_width > 0)
		arg = ft_check_width(arg, a);
	return(ft_printf_putstr_utf_8(a, arg));
}

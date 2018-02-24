/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_oct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:54:40 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/21 13:29:30 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static char	*ft_delate_zero(char *s)
{
	char *tmp;

	tmp = s;
	while (*s == '0')
		s++;
	s = ft_strdup(s);
	ft_strdel(&tmp);
	return (s);
}

char		*ft_printf_itoa_oct(uintmax_t num, t_arg *arg)
{
	char	*oct;
	char	*s;
	int		i;

	oct = "01234567";
	i = 22;
	if (num == 0 && arg->p_switch != 1 && arg->prefix != 48)
		return (ft_strdup("0"));
	s = ft_strnew(23);
	ft_strcpy(s, "0");
	while (i > 0)
	{
		s[i--] = oct[num & 07];
		num >>= 3;
	}
	return (ft_delate_zero(s));
}

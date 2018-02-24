/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_bin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:20:00 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/21 13:28:35 by jpinyot          ###   ########.fr       */
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

char		*ft_printf_itoa_bin(uintmax_t num)
{
	char	*s;
	int		i;

	i = 64;
	s = (char *)malloc(sizeof(uintmax_t) * 8 + 1);
	ft_strcpy(s, "0");
	while (i > 0)
	{
		s[i--] = ((num & 0x1) + '0');
		num >>= 1;
	}
	return (ft_delate_zero(s));
}

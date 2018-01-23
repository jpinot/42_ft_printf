/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:59:43 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/23 09:01:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static char	*ft_delate_zero(char *s)
{
	while (*s == '0')
		s++;
	return (s);
}

char		*ft_printf_itoa_hex(uintmax_t num, int conv)
{
	char	*up;
	char	*down;
	char	*s;
	int		i;

	up = "0123456789ABCDEF";
	down = "0123456789abcdef";
	i = 16;
	s = (char *)malloc(sizeof(uintmax_t) * 2 + 1);
	ft_strcpy(s, "0");
	if (conv == 'X')
	{
		while (i > 0)
		{
			s[i--] = up[(num & 0xF)];
			num >>= 4;
		}
	}
	else
	{
		while (i > 0)
		{
			s[i--] = down[(num & 0xF)];
			num >>= 4;
		}
	}
	return(ft_delate_zero(s));
}

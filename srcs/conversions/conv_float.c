/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:13:37 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/29 18:09:55 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_itoa_len(float n)
{
	size_t len;

	len = 2;
	while(n /= 10)
		len++;
	return (len);
}

static char	*ft_printf_itoa_float(float n)
{
	size_t  len;
	char    *s;

	len = ft_itoa_len(n);
	if (!(s = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
//	while (len--)
//	{
//		s[len] = n % 10 + 48;
//		n = n / 10;
//	}
	return (s);
}
int			conv_float(va_list ap, t_arg *arg)
{
	float	num;
	int		exp;
	int		man;

	num = (float)va_arg(ap, double);
	exp = (int)num & 0x7fffff;
	ft_putnbr(exp);
	return (0);
}

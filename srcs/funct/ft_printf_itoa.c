/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:00:51 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/23 08:55:03 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_len(intmax_t n)
{
	size_t len;

	if (n < 0)
		len = 3;
	else
		len = 2;
	n = n * -1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_printf_itoa(intmax_t n)
{
	size_t	len;
	char	*s;
	size_t	neg;

	len = ft_len(n);
	neg = 0;
	if (n < 0)
	{
		n = n * -1;
		neg = 1;
	}
	if (!(s = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	if (neg == 1)
		s[0] = '-';
	return (s);
}

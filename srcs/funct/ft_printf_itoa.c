/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 18:00:51 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/04 14:49:50 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static int	ft_len(uintmax_t n)
{
	size_t len;

	len = 2;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_printf_itoa(uintmax_t n)
{
	size_t	len;
	char	*s;

	len = ft_len(n);
	if (!(s = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_oct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 08:54:40 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/23 09:14:02 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static char	*ft_delate_zero(char *s)
{
	while (*s == '0')
		s++;
	return (s);
}

char		*ft_printf_itoa_oct(uintmax_t num)
{
	char	*oct;
	char	*s;
	int		i;

	oct = "01234567";
	i = 16;
	s = (char *)malloc((sizeof(void) * 8) / 3 + 1);
	ft_strcpy(s, "0");
	while (i > 0)
	{
		s[i--] = oct[num & 07];
		num >>= 3;
	}
	return(ft_delate_zero(s));
}

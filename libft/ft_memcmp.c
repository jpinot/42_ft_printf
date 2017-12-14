/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:57:10 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 00:20:52 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *d1;
	unsigned char *d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (n--)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		d1++;
		d2++;
	}
	return (0);
}

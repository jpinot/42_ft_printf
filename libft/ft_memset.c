/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:11:05 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/13 00:59:20 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char*)str;
	if (n)
	{
		while (n--)
			*s++ = (unsigned char)c;
	}
	return (str);
}

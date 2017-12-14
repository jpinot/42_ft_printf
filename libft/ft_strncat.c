/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 01:56:16 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/17 03:06:12 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *str, size_t n)
{
	size_t i;
	size_t a;

	i = 0;
	a = (size_t)ft_strlen(dest);
	while (str[i] && i < n)
	{
		dest[a] = (char)str[i];
		i++;
		a++;
	}
	dest[a] = 0;
	return (dest);
}

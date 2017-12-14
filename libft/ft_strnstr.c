/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:40:17 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 00:13:30 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	size_t	i;
	size_t	a;
	size_t	t;
	size_t	l;

	a = 0;
	h = (char *)haystack;
	while (h[a] && len > 0)
	{
		i = 0;
		t = a;
		l = len;
		while (h[t] == needle[i] && needle[i] != 0 && l > 0)
		{
			i++;
			t++;
			l--;
		}
		if (needle[i] == 0)
			return (&h[t - ft_strlen(needle)]);
		a++;
		len--;
	}
	return (NULL);
}

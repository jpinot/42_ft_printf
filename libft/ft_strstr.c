/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:17:23 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 00:13:08 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	size_t	i;
	size_t	a;
	size_t	t;

	a = 0;
	h = (char *)haystack;
	if (*haystack == 0 && *needle == 0)
		return (h);
	while (h[a])
	{
		i = 0;
		t = a;
		while (h[t] == needle[i] && needle[i] != 0)
		{
			i++;
			t++;
		}
		if (needle[i] == 0)
			return (&h[t - ft_strlen(needle)]);
		a++;
	}
	return (NULL);
}

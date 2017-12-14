/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:50:40 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 00:16:13 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*c;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	if (!(c = (char *)malloc(sizeof(char) *
					(ft_strlen(s2) + ft_strlen(s1) + 1))))
		return (NULL);
	while (*s1)
	{
		c[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		c[i] = *s2;
		i++;
		s2++;
	}
	c[i] = '\0';
	return (c);
}

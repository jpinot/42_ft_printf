/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:15:12 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/17 04:55:50 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	len_c(const char *s, char c)
{
	size_t i;
	size_t cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static int	ft_le(const char *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		cnt++;
		i++;
	}
	return (cnt);
}

static char	**cpy_ft(char **str, const char *s, char c)
{
	int		i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str[k] = ft_strsub(s, i, ft_le(&s[i], c));
			i += ft_le(&s[i], c);
		}
		while (s[i] == c && s[i])
			i++;
		k++;
	}
	str[k] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (len_c(s, c) + 1))))
		return (NULL);
	if (len_c(s, c) == 0)
	{
		*str = 0;
		return (str);
	}
	str = cpy_ft(str, s, c);
	return (str);
}

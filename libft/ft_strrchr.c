/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 22:22:27 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 00:13:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;

	s = (char *)&str[ft_strlen(str) + 1];
	while (s-- != str)
	{
		if (*s == c)
			return (s);
	}
	return (NULL);
}

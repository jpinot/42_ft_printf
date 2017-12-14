/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:04:37 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/17 19:50:57 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	if (len <= 0)
		return (ft_strnew(1));
	i = -1;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		len--;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s = s + i;
	i = 0;
	while (i < len)
		str[i++] = *s++;
	str[i] = 0;
	return (str);
}

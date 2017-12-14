/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 03:09:44 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/17 03:35:42 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *str, size_t size)
{
	size_t d_len;
	size_t s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(str);
	if (size <= d_len)
		return (size + s_len);
	if (s_len < size - d_len)
	{
		ft_memcpy(dst + d_len, str, s_len);
		dst = dst + d_len + s_len;
	}
	else
	{
		ft_memcpy(dst + d_len, str, size - d_len - 1);
		dst = dst + size - 1;
	}
	*dst = 0;
	return (d_len + s_len);
}

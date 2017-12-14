/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:54:34 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/09 22:34:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;

	if (!(copy = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	else
		return (ft_strcpy(copy, str));
}

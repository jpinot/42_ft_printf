/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:58:25 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/17 01:00:25 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		n;
	size_t	i;
	size_t	neg;

	n = 0;
	i = 0;
	neg = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			neg++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (10 * n) + (str[i] - 48);
		i++;
	}
	if (neg > 0)
		n *= -1;
	return (n);
}

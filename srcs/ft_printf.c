/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/14 23:27:42 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

static char	*ft_print_until(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (c[i] == '%')
			return (c + i + 1);
		write(1, &c[i], 1);
		i++;
	}
	return (NULL);
}

int			ft_printf(const char *restrict format, ...)
{
	char	*tmp;
	va_list	ap;

	tmp = (char *)format;
	va_start(ap, format);
	while (((tmp = ft_print_until(tmp)) != NULL))
	{
		ft_print_var(ap, tmp);
		tmp++;
	}
	return (0);
}

int     main(void)
{
	int res = 9;
	int res2 = 454;

	ft_printf("El resultado es: %d\n o es: %d", res, res2);
	return (0);
}

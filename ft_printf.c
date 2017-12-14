/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/14 01:09:31 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

char	*ft_print_until(char *c)
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

int		ft_printf(const char *restrict format, ...)
{
	char	*tmp;
	int		pos;
	va_list	ap;
	char	*res;

	tmp = (char *)format;
	pos = 1;
	va_start(ap, format);
	while (((tmp = ft_print_until(tmp)) != NULL))
	{
		*res = va_arg(ap, int) + 48;
		write(1, res, 1);
		tmp++;									//TEMPORAL!!!!
//		ft_print_var(tmp, ad);
	}
	return (0);
}

int     main(void)
{
	int res = 9;
	int res2 = 454;

	ft_printf("El resultado es: %i\n o es: %f", res, res2);
	return (0);
}

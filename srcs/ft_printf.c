/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/28 18:58:28 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

static char	*ft_print_until(char *c)
{

	while (*c)
	{
		if (*c == '%')
			return (c + 1);
		write(1, c, 1);
		c++;
	}
	return (NULL);
}

char       *ft_printf_flags(va_list ap, char *s)
{
	t_arg   arg;

	arg = ft_printf_new_arg(&arg);
	s = ft_check_flags(s, &arg);
	s = ft_check_field_with(ap, s, &arg);
	s = ft_check_precision(ap, s, &arg);
	s = ft_check_length(s, &arg);
	int z = 0;
	if (*s == 'i' || *s =='d' || *s == 'D')
		z = conv_int(ap, &arg, *s);
	if (*s == 'u' || *s == 'U' || *s == 'x' || *s == 'X' || *s == 'o' || *s == 'O')
		z = conv_unsigned_int(ap, &arg, *s);
	if (*s == 'p')
		z = conv_void(ap, &arg, *s);
	if (*s == 'c')
		z = conv_char(ap, &arg);
	if (*s == 'C')
		z = conv_utf_8(ap, &arg);
	if (*s == 's')
		z = conv_str(ap, &arg);
	if (*s == 'S')
		z = conv_str_utf_8(ap, &arg);
	if (*s == '%')
		write(1, "%", 1);
//	if (*s == 'p')
//		z = conv_void(ap, &arg);
	s++;
	return (s);
}

int			ft_printf(const char *restrict format, ...)
{
	char	*tmp;
	va_list	ap;

	tmp = (char *)format;
	va_start(ap, format);
	while (((tmp = ft_print_until(tmp)) != NULL))
		tmp  = ft_printf_flags(ap, tmp);
	return (0);
}

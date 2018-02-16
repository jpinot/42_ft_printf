/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/16 17:20:07 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

static char	*ft_print_until(char *c, int *cnt)
{
	while (*c)
	{
		if (*c == '%' && c[1] != 0)
			return (c + 1);
		else if (*c == '%' && c[1] == 0)
			return (NULL);
		write(1, c, 1);
		c++;
		*cnt += 1;
	}
	return (NULL);
}

char       *ft_printf_flags(va_list ap, char *s, int *z)
{
	t_arg   arg;
	int		i;

	i = *z;
	arg = ft_printf_new_arg(&arg);
	s = ft_check_flags(s, &arg);
	s = ft_check_field_with(ap, s, &arg);
	s = ft_check_precision(ap, s, &arg);
	s = ft_check_length(s, &arg);
	if (*s == 'i' || *s =='d' || *s == 'D')
		*z += conv_int(ap, &arg, *s);
	else if (*s == 'u' || *s == 'U' || *s == 'x' || *s == 'X' || *s == 'o' || *s == 'O' || *s == 'b')
		*z += conv_unsigned_int(ap, &arg, *s);
	else if (*s == 'p')
		*z += conv_void(ap, &arg, *s);
	else if (*s == 'c' && arg.lenght != 'l')
		*z += conv_char(ap, &arg);
	else if (*s == 'C' || (*s == 'c' && arg.lenght == 'l'))
		*z += conv_utf_8(ap, &arg);
	else if (*s == 's' && arg.lenght != 'l')
		*z += conv_str(ap, &arg);
	else if (*s == 'S' || (*s == 's' && arg.lenght == 'l'))
		*z += conv_str_utf_8(ap, &arg);
	else if (*s == '%')
		*z += ft_printf_putchar('%', &arg);
	else if (*s != 0)
		*z += ft_printf_putchar(*s, &arg);
	else
		return (s);
	return (s + 1);
}

int			ft_printf(const char *restrict format, ...)
{
	char	*tmp;
	va_list	ap;
	int		cnt;

	cnt = 0;
	tmp = (char *)format;
	va_start(ap, format);
	while (((tmp = ft_print_until(tmp, &cnt)) != NULL))
	{
		tmp  = ft_printf_flags(ap, tmp, &cnt);
		if (cnt == -1)
			return (-1);
	}
	va_end(ap);
	return (cnt);
}

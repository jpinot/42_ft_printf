/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_from_int_to_utf_8.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 09:49:14 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/29 18:11:55 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

static char	*from_int_to_utf_1(int c)
{
	char *a;

	a = ft_strnew(2);
	*a = (char)c;
	return (a);
}

static char *from_int_to_utf_2(int c)
{
	char *a;

	a = (char *)malloc(sizeof(char) * 2);
	a[1] = c & 0x3f;
	a[1] = 0x80 | a[1];
	c >>= 6;
	a[0] = c & 0x1f;
	a[0] = 0xc0 | a[0];
	return (a);
}

static char *from_int_to_utf_3(int c)
{
	char *a;

	a = (char *)malloc(sizeof(char) * 3);
	a[2] = c & 0x3f;
	a[2] = 0x80 | a[2];
	c >>= 6;
	a[1] = c & 0x3f;
	a[1] = 0x80 | a[1];
	c >>= 6;
	a[0] = c & 0xf;
	a[0] = 0xe0 | a[0];
	return (a);
}

static char *from_int_to_utf_4(int c)
{
	char *a;

	a = (char *)malloc(sizeof(char) * 4);
	a[3] = c & 0x3f;
	a[3] = 0x80 | a[3];
	c >>= 6;
	a[2] = c & 0x3f;
	a[2] = 0x80 | a[2];
	c >>= 6;
	a[1] = c & 0x3f;
	a[1] = 0x80 | a[1];
	c >>= 6;
	a[0] = c & 0x7;
	a[0] = 0xf0 | a[0];
	return (a);
}

char		*ft_printf_from_int_to_utf_8(int c)
{
	char *a;

	a = NULL;
	if (c <= 127)
		a = from_int_to_utf_1(c);
	else if (c >= 128 && c <= 2047)
		a = from_int_to_utf_2(c);
	else if (c >= 2048 && c <= 65534)
		a = from_int_to_utf_3(c);
	else if (c >= 65535 && c <= 2097150)
		a = from_int_to_utf_4(c);
//	write(1, "%", 1);
	return(a);
}

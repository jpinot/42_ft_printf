/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/14 15:40:30 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
int     main(void)
{
	setlocale(LC_ALL, "");	
//	intmax_t		res = 30000000345;
//	unsigned int	res2 = 320;
//	char			s[] = "Hola primoh como va todo";
//	int				a;
//	wchar_t			wc[20] = L"ghfr";
//	wchar_t			pc[20] = L"ghfr";
//	ft_putnbr(res);
//	ft_putchar('\n');
//	short w = 21458766755;
//	int w = 22;
//	char str1[] = "Hola";
//	char str2[] = "que";
//	char str3[] = "tal";
//	char **str = NULL;
//	str[0] = str3;
//	str[1] = str2;
//	str[2] = str1;
//	ft_putnbr(ft_power(10, 3));
//	char s[10] = "Hola";
int i =	ft_printf("%o, %o, %o, %o", 112, 23, 778, 234);
	write(1, "\n", 1);
int j = printf("%o, %o, %o, %o", 112, 23, 778, 234);
	printf("\nf: %i\no: %i", i, j);
//	ft_putnbr(i);
//	ft_putnbr(j);
//	while(1 > 0)
//		*s = '&';
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/20 16:36:43 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
int     main(void)
{
	setlocale(LC_ALL, "");	

	wchar_t s[4];

	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';

	int i =	ft_printf("%9.6ls %S", s, (wchar_t *)'a');
	write(1, "\n", 1);
//	int j = printf("%9.6ls %S", s, (wchar_t *)'a');
//	printf("\nf: %i\no: %i", i, j);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:53:38 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/23 10:35:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

int     main(void)
{
//	intmax_t		res = 30000000345;
//	unsigned int	res2 = 320;
//	char			s[] = "Hola primoh como va todo";
//	int				a;
	wchar_t			wc[22] =  L"漢字";
//	ft_putnbr(res);
//	ft_putchar('\n');
	ft_printf("El character es: |%#x| o puede ser %%100\n", 248);
//	printf("El character es: |%#15.14o| o puede ser %%100\n", 2147483647);
	printf("|ABC%S|", wc);
	return (0);
}

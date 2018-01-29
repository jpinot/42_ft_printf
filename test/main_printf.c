/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:33:11 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/28 20:12:47 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_test(int a)
{
	char c = 'w';
	c = a + '0';
	printf("%x\n", a);
	write(1, &c, 1);
	write(1, "E", 1);
}
char *decToHex(uintmax_t input)
{
	char *output = malloc(sizeof(uintmax_t) * 2 + 3);
	strcpy(output, "0");
	char HEX[] = "01234567";
	int index = 10;
	while (index > 0 )
	{
		output[index--] = HEX[(input & 07)];
	    input >>= 3;
	}
	return output;
}

char	from_c_to_u(int c)
{
	char a;
	int i = 0;

	while (i < 4)
	{
		a = (c & 0x100);
		i++;
		c >>= 8;
	}
	return(a);
}

int		main(void)
{
//	intmax_t x = 2147483947;
//	x = (short)x;
//	short w = 2147483947;
//	printf("%ji\n", x);
	int x = -10;
	long w = 4294967296;
	printf("%D\n", x);
	x += 4294967296;
	printf("%i", x);
	return(0);
}

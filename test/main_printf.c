/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:33:11 by jpinyot           #+#    #+#             */
/*   Updated: 2018/01/23 09:38:12 by jpinyot          ###   ########.fr       */
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

int		main(void)
{
	float	i = 32.34;
	long	a = (int)i;
	char 	c = 'h';
	uintmax_t		x = 12345678912345;
	x = (long)x;
//	x = (int)x;

	printf("|%s|\n", decToHex(12344));
	printf("|%o|\n", 12344);
//	ft_test(a);
	return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 00:17:23 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/17 02:10:43 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;
	int nb[10];

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n == -2147483648)
		ft_putstr_fd("2147483648", fd);
	if (n == 0)
		ft_putchar_fd('0', fd);
	while (n > 0)
	{
		nb[i] = n % 10;
		n = n / 10;
		i++;
	}
	while (i--)
		ft_putchar_fd(nb[i] + 48, fd);
}

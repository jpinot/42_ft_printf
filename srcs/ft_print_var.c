/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:43:14 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/14 23:27:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

static char	ft_check_type(char *c)
{
	while(c == conversions)

static int	ft_check_type(va_list ap, char *c)
{
	if (ft_check_input(c) == 'd')
		ft_putnbr(va_arg(ap, int));
	return (0);
}

void		ft_print_var(va_list ap, char *c)
{
	ft_check_type(ap, c);
}

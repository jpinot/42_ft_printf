/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 23:43:14 by jpinyot           #+#    #+#             */
/*   Updated: 2017/12/14 00:27:37 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

//int		ft_check_type(const char *c)
//{
	

int		*ft_print_var(const char *c, int pos, ...)
{
	va_list	ad;
	int i;

	va_start(ad, pos);
	i = va_arg(ad, int);
	printf("%i", i);
	return (0);
}

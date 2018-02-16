/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:54:26 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/16 15:50:16 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
/*
static void ft_pf_memdel(char **ap)
{
	if (ap != NULL)
	{
		if (*ap)
			free(*ap);
		*ap = NULL;
	}
}
*/
int		ft_pf_write_until(char c, int j, int fd)
{
	int i;

	i = j;
	while (i-- > 0)
		write(fd, &c, 1);
	return (j);
}

int		ft_pf_putstr(char *s, int fd)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i += 1;
		}
	}
	return (i);
}

int		ft_pf_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_pf_putstr_until(char *s, int j, int fd)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (i < j && s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	return (j);
}

int		ft_pf_strlen(const char *str)
{
	char *s;

	s = (char *)str;
	while (*s)
		s++;
	return (s - str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 08:20:08 by jpinyot           #+#    #+#             */
/*   Updated: 2018/02/23 15:39:56 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include <stdio.h>

char	*ft_check_flags(char *s, t_arg *arg)
{
	while (*s == '#' || *s == '0' || *s == '-' || *s == '+'
			|| *s == ' ' || *s == 39)
	{
		if (*s == '#')
			arg->prefix = 48;
		if (*s == '0')
			arg->pad_zero = 1;
		if (*s == '-')
			arg->left_justify = 1;
		if (*s == ' ' && arg->force_positive == 0)
			arg->force_positive = 32;
		if (*s == '+')
			arg->force_positive = 1;
		s++;
	}
	if (arg->left_justify)
		arg->pad_zero = 0;
	return (s);
}

char	*ft_check_field_with(va_list ap, char *s, t_arg *arg)
{
	while (*s == '*' || ft_isdigit(*s))
	{
		if (ft_isdigit(*s))
		{
			arg->filed_width = 0;
			while (ft_isdigit(*s))
			{
				arg->filed_width = arg->filed_width * 10 + (*s - '0');
				s++;
			}
		}
		if (*s == '*')
		{
			if ((arg->filed_width = va_arg(ap, int)) < 0)
			{
				arg->left_justify = 1;
				arg->filed_width *= -1;
			}
			s++;
		}
	}
	return (s);
}

char	*ft_check_precision(va_list ap, char *s, t_arg *arg)
{
	if (*s == '.')
	{
		arg->p_switch = 1;
		s++;
		if (*s == '*')
		{
			s++;
			arg->precision = va_arg(ap, int);
			return (s);
		}
		else
		{
			while (ft_isdigit(*s))
			{
				arg->precision = arg->precision * 10 + (*s - '0');
				s++;
			}
			return (s);
		}
	}
	return (s);
}

char	*ft_check_length(char *s, t_arg *arg)
{
	if (*s == 'h' && s[1] == 'h')
	{
		arg->lenght = 104104;
		return (s + 2);
	}
	else if (*s == 'l' && s[1] == 'l')
	{
		arg->lenght = 108108;
		return (s + 2);
	}
	else if (*s == 'l' || *s == 'h' || *s == 'j'
			|| *s == 'z' || *s == 't' || *s == 'L')
	{
		arg->lenght = *s + 0;
		return (s + 1);
	}
	return (s);
}

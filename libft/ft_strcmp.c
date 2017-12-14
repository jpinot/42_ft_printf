/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:10:06 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 00:17:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *d1;
	unsigned char *d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (*d1 || *d2)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		d1++;
		d2++;
	}
	return (0);
}

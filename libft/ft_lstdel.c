/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:42:04 by jpinyot           #+#    #+#             */
/*   Updated: 2017/11/16 20:47:12 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *lst;

	lst = *alst;
	while (lst)
	{
		tmp = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = tmp;
	}
	*alst = NULL;
}

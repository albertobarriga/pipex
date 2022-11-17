/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:26:39 by abarriga          #+#    #+#             */
/*   Updated: 2022/10/03 20:08:37 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a;
	t_list	*node1;

	if (!lst || !f)
		return (0);
	node1 = 0;
	while (lst)
	{
		a = ft_lstnew(0);
		if (!a)
		{
			ft_lstclear(&node1, del);
			return (0);
		}
		a->content = f(lst->content);
		ft_lstadd_back(&node1, a);
		lst = lst->next;
	}
	return (node1);
}

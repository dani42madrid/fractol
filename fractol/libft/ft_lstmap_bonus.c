/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:55:49 by danielm3          #+#    #+#             */
/*   Updated: 2025/01/26 15:53:30 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			if (del)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

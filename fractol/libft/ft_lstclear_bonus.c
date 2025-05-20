/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:09:10 by danielm3          #+#    #+#             */
/*   Updated: 2025/01/26 15:53:18 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*freed;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		freed = temp;
		temp = temp->next;
		del(freed->content);
		free(freed);
	}
	*lst = NULL;
}

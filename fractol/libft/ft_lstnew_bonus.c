/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:49:48 by danielm3          #+#    #+#             */
/*   Updated: 2025/01/26 15:53:32 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newitem;

	newitem = (t_list *)malloc(sizeof(t_list));
	if (!newitem)
		return (NULL);
	newitem->content = content;
	newitem->next = NULL;
	return (newitem);
}

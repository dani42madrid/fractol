/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:05:55 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/20 23:50:53 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*joined;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	ft_memmove(joined, s1, s1len);
	ft_memmove(joined + s1len, s2, s2len);
	joined[s1len + s2len] = '\0';
	return (joined);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:30:12 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/21 20:50:09 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sublen;

	if (start >= ft_strlen(s))
	{
		substr = (char *)ft_calloc(1, 1);
		return (substr);
	}
	if (start + len > ft_strlen(s))
		sublen = ft_strlen(s) - start;
	else
		sublen = len;
	substr = (char *)malloc((sublen + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_memmove(substr, s + start, sublen);
	substr[sublen] = '\0';
	return (substr);
}

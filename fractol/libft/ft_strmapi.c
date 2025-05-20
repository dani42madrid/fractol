/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:53:40 by danielm3          #+#    #+#             */
/*   Updated: 2025/01/28 14:02:24 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f((unsigned int)i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:11:34 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/14 13:43:53 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	const char		*last;

	uc = (unsigned char)c;
	i = 0;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			last = &s[i];
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return ((char *)last);
}

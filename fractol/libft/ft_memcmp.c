/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:12:11 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/16 14:48:56 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*sc1;
	const unsigned char	*sc2;
	size_t				i;

	sc1 = (const unsigned char *)s1;
	sc2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (sc1[i] != sc2[i])
			return (sc1[i] - sc2[i]);
		i++;
	}
	return (0);
}

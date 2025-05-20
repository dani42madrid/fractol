/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:33:16 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/21 13:46:26 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	u1;
	unsigned char	u2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		u1 = (unsigned char)s1[i];
		u2 = (unsigned char)s2[i];
		if (u1 != u2)
			return (u1 - u2);
		i++;
	}
	return (0);
}

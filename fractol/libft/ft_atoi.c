/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:14:46 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/21 23:25:19 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	mincount;
	int	result;

	i = 0;
	result = 0;
	mincount = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mincount = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (result * mincount);
}

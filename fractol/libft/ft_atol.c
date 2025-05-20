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

// (40 and 42) prevents long overflow, which would cause und. behav.
// (47) returns (LONG_MIN) in case the string has anything else than a number

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\f'
		|| c == '\r' || c == '\t' || c == '\v');
}

long	ft_atol(const char *str)
{
	long	mincount;
	long	result;

	result = 0;
	mincount = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		mincount = 1 - 2 * (*str == '-');
		str++;
	}
	if (!ft_isdigit(*str))
		return (LONG_MIN);
	while (ft_isdigit(*str) && result <= (LONG_MAX / 10))
	{
		if (result == (LONG_MAX / 10) && (*str - '0') > (LONG_MAX % 10))
			return (LONG_MIN);
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (LONG_MIN);
	return (result * mincount);
}

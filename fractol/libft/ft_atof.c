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

static int	parse_whole_part(const char *str, int *i)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	parse_decimal_part(const char *str, int *i)
{
	double	result;
	double	divisor;

	result = 0.0;
	divisor = 10.0;
	if (str[*i] == '.' || str[*i] == ',')
		(*i)++;
	while (ft_isdigit(str[*i]))
	{
		result += (str[*i] - '0') / divisor;
		divisor *= 10.0;
		(*i)++;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	res;

	i = 0;
	sign = 1;
	res = 0.0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != ',')
		return (0.0);
	res += parse_whole_part(str, &i);
	if (str[i] == '.' || str[i] == ',')
		res += parse_decimal_part(str, &i);
	if (str[i] != '\0')
		return (0.0);
	return (sign * res);
}

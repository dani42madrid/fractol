/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 22:08:01 by danielm3          #+#    #+#             */
/*   Updated: 2024/12/24 22:08:03 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_arrayalloc(int number, int digits, char sign)
{
	char	*array;

	if (sign == '-')
	{
		number *= -1;
		digits += 1;
	}
	array = (char *)malloc((digits + 1) * sizeof(char));
	if (!array)
		return (NULL);
	array[digits] = '\0';
	digits--;
	while (digits > 0)
	{
		array[digits--] = ((number % 10) + '0');
		number /= 10;
	}
	array[digits] = number + '0';
	if (sign == '-')
		array[0] = sign;
	return (array);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		number;
	char	sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	number = n;
	sign = '+';
	if (n < 0)
	{
		n *= -1;
		sign = '-';
	}
	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (ft_arrayalloc(number, digits, sign));
}

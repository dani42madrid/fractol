/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:15:34 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/22 20:42:21 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_wrong_args(void)
{
	ft_putendl_fd("\nIncorrect arguments. Please enter:\n", 2);
	ft_putendl_fd("Option 1: mandelbrot\nor", 2);
	ft_putendl_fd("Option 2: julia <real number> <imaginary number> "
		"(number range: -2 to + 2)\n", 2);
	exit(EXIT_FAILURE);
}

static int	decimals_and_range_check(char *s)
{
	int		count;
	double	number;

	count = 0;
	number = ft_atof(s);
	while (*s)
	{
		if (*s == '.' || *s == ',')
			count++;
		s++;
	}
	if (count > 1 || (number > 2.0 || number < -2.0))
		print_wrong_args();
	return (1);
}

void	check_args(int argc, char **argv)
{
/* 	double	real;
	double	imaginary;

	real = 0;
	imaginary = 0; */
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 11))
		return ;
	else if (argc == 2 && !ft_strncmp(argv[1], "julia", 6))
		return ; // CHANGE THIS TO CALL JULIA WITH DEFAULT VALUES
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 6)
		&& decimals_and_range_check(argv[2])
		&& decimals_and_range_check(argv[3]))
		return ;
	else
		print_wrong_args();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:15:34 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/30 17:53:09 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Parses and validates command-line arguments.
Initializes fractal type and max_iter depending on input.
Exits with error message if input format is invalid. */

void	check_args(int argc, char **argv, t_map *map)
{
	if (argc != 2 && argc != 4 && argc != 5)
		print_wrong_args();
	else if (!ft_strncmp(argv[1], "mandelbrot", 11))
	{
		init_mandelbrot(map);
		map->max_iter = 75;
		if (argc == 3)
			map->max_iter = ft_atoi(argv[2]);
	}
	else if (!ft_strncmp(argv[1], "julia", 6)
		&& (argc == 2 || ((argc == 4 || argc == 5)
				&& decimals_and_range_check(argv[2])
				&& decimals_and_range_check(argv[3]))))
	{
		init_julia(argc, argv, map);
		map->max_iter = 75;
		if (argc == 5)
			map->max_iter = ft_atoi(argv[4]);
	}
	else
		print_wrong_args();
}

/* Validates if a string is a proper decimal number within range.
Allows only one decimal point or comma. 
Accepted range: from -5.0 to +5.0. Exits if invalid. */
int	decimals_and_range_check(char *s)
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
	if (count > 1 || (number > 5.0 || number < -5.0))
		print_wrong_args();
	return (1);
}

/* Displays usage instructions for the program.
Shows valid command-line formats and expected value ranges.
Exits the program with failure if arguments are incorrect. */
void	print_wrong_args(void)
{
	ft_putendl_fd("\nIncorrect arguments. Please enter:\n", 2);
	ft_putendl_fd("Option 1:\t./fractol mandelbrot\n", 2);
	ft_putendl_fd("Option 2:\t./fractol julia\n", 2);
	ft_putendl_fd("Option 3:\t./fractol julia <real_part> <imag_part> "
		"<max_iterations>", 2);
	ft_putendl_fd("\t\t(real and imaginary values: -5.0 to +5.0)", 2);
	ft_putendl_fd("\t\t(max_iterations recommended: 50 to 300)\n", 2);
	exit(EXIT_FAILURE);
}

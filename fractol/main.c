/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:20:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/22 13:33:00 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_wrong_args()
{
	char	*error_msg;
	char	*tmp_join;
	
	error_msg = ft_strdup("Incorrect arguments. Please enter:\n");
	tmp_join = ft_strjoin(error_msg, "Option 1: mandlebrot.\n");
	free(error_msg);
	error_msg = ft_strjoin(tmp_join, "Option 2: julia <real part>"
		"<imaginary part>\nNumber range: -2 ~ +2\n");
	free(tmp_join);
	ft_putendl_fd(error_msg, 2);
	free(error_msg);
	exit(EXIT_FAILURE);
}
static int	decimal_separators(char *s)
{
	int	count;

	count = 0;

	while (*s)
	{
		if (*s == '.' || *s == ',')
			count++;
	}
	return (count);
}


void	check_args(int argc, char **argv)
{
	double	real;
	double 	imaginary;
	
	real = 0;
	imaginary = 0;
	if ((ft_strncmp(argv[1], "mandlebrot", 10) != 0 && argc != 2)
		|| (ft_strncmp(argv[1], "julia", 5) != 0 && (argc != 4 && argc != 2)))
		print_wrong_args();
	if (ft_atof(argv[2]) > 2.0 || ft_atof(argv[2]) < -2.0)
		print_wrong_args();
		
}

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	
	return (0);
}


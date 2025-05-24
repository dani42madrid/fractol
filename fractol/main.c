/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:20:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/23 18:05:43 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	printf("%i\n", escape_iterations( 3.0,  0.0, 50));  // expect 1
	printf("%i\n", escape_iterations( 0.0,  3.0, 50));  // expect 1
	printf("%i\n", escape_iterations( 1.0,  1.0, 50));  // expect 2
	printf("%i\n", escape_iterations( 0.5,  0.5, 50));  // expect 5
	printf("%i\n", escape_iterations(-0.75, 0.10, 50)); // expect 33
	return (0);
}

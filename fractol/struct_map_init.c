/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:43:19 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/24 18:25:27 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_map *map)
{
	map->cr = 0;
	map->ci = 0;
	map->x_min = -2.0;
	map->x_max = 1.0;
	map->y_min = -1.0;
	map->y_max = 1.0;
	map->max_iter = 100;
}

void	init_julia(int argc, char **argv, t_map *map)
{
	map->x_min = -1.5;
	map->x_max = 1.5;
	map->y_min = -1.5;
	map->y_max = 1.5;
	map->max_iter = 100;
	if (argc == 2)
	{
		map->cr = -0.7269;
		map->ci = 0.1889;
	}
	else
	{
		map->cr = ft_atof(argv[2]);
		map->ci = ft_atof(argv[3]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_and_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:39:56 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/30 17:54:46 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Initializes the MLX environment and image buffer.
Creates a window and image of fixed size and stores image data address. */
void	mlx_and_img_creation(t_mlx *mlx)
{
	mlx->width = 960;
	mlx->height = 960;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"fractol");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->data_address = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
}

/*	
	Converts a pixel’s column index in the window into the corresponding
	real‐axis coordinate in the complex‐plane window via linear 
	interpolation.
*/
double	map_x(t_mlx *mlx, t_map *map, int x)
{
	return (map->x_min + (double)x / (mlx->width - 1)
		* (map->x_max - map->x_min));
}

/*
	Converts a pixel’s row index in the window into the corresponding
	imaginary‐axis coordinate in the complex‐plane window via linear 
	interpolation.
*/
double	map_y(t_mlx *mlx, t_map *map, int y)
{
	return (map->y_min + (double)y / (mlx->height - 1)
		* (map->y_max - map->y_min));
}

/* Sets default values for Mandelbrot rendering. Initial complex values and
visible range are fixed. */
void	init_mandelbrot(t_map *map)
{
	map->cr = 0;
	map->ci = 0;
	map->x_min = -2.0;
	map->x_max = 1.0;
	map->y_min = -1.5;
	map->y_max = 1.5;
	map->type = TYPE_MANDEL;
}

/* Sets default values and user-defined constants for Julia rendering.
If only "julia" is passed, uses a predefined complex constant.
If arguments are included, sets cr and ci from user input. */
void	init_julia(int argc, char **argv, t_map *map)
{
	map->x_min = -1.5;
	map->x_max = 1.5;
	map->y_min = -1.5;
	map->y_max = 1.5;
	map->type = TYPE_JULIA;
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

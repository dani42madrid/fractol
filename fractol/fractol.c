/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:03:31 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/24 18:38:42 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

/*
	Calculates how many iterations the sequence zₙ₊₁ = zₙ² + c stays bounded
	(with |z|² <= 4) before exceeding max_iter. Uses the formula:
		zₙ₊₁ = (zr² – zi² + cr) + i*(2*zr*zi + ci)
	which is is the defining iteration for the classic quadratic fractals:
	Mandelbrot and Julia sets. 
*/
int	escape_iterations(double zr, double zi, t_map *map)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < map->max_iter)
	{
		tmp = zr * zr - zi * zi + map->cr;
		zi = 2.0 * zr * zi + map->ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	mlx_and_img_creation(t_mlx *mlx)
{
	mlx->width = 1280;
	mlx->height = 1280;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width, mlx->height,
			"fractol");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->data_address = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
}

void	init_map_struct(char **argv, t_map *map)
{
	
}

void	put_pixel(t_mlx *mlx, int x, int y, int colour)
{
	int	offset;
	
	
}

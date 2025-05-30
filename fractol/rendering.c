/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:01:34 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/30 11:28:40 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Calculates how many iterations the sequence zₙ₊₁ = zₙ² + c stays bounded
	(with |z|² <= 4) before exceeding max_iter. Uses the formula:
		zₙ₊₁ = (zr² – zi² + cr) + i*(2*zr*zi + ci)
	which is is the defining iteration for the classic quadratic fractals:
	Mandelbrot and Julia sets. 
	
	Both sets use the same iteration:
	zₙ₊₁ = zₙ² + c

	In Mandelbrot, z₀ = 0 and c = pixel coordinate.  
	In Julia, z₀ = pixel coordinate and c = constant from user input.
*/

/* Iterates Mandelbrot formula to check if point escapes.
Returns number of iterations before escape or max_iter.
Used to color each pixel based on escape time. */
int	escape_mandelbrot(double c_re, double c_im, int max_iter)
{
	int		iter;
	double	zr;
	double	zi;
	double	tmp;

	iter = 0;
	zr = 0.0;
	zi = 0.0;
	while (zr * zr + zi * zi <= 4.0 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + c_re;
		zi = 2.0 * zr * zi + c_im;
		zr = tmp;
		iter++;
	}
	return (iter);
}

/* Iterates Julia formula using given complex constant.
Returns iteration count until escape or max_iter.
Behavior depends on user-specified Julia parameters. */
int	escape_julia(double z_re, double z_im, t_map *map)
{
	int		iter;
	double	tmp;

	iter = 0;
	while (z_re * z_re + z_im * z_im <= 4.0 && iter < map->max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + map->cr;
		z_im = 2.0 * z_re * z_im + map->ci;
		z_re = tmp;
		iter++;
	}
	return (iter);
}

/* Calculates color from iteration count using smooth gradients.
Blue for fast escapes, green for mid, red for slow escapes.
Returns black if the point is inside the fractal (no escape). */
int	pick_colour(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		colour;

	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	if (iter < 2)
		return (0x111111);
	colour = (r << 16) | (g << 8) | b;
	return (colour);
}

void	render(t_mlx *mlx, t_map *map)
{
	int		x;
	int		y;
	int		iter;
	int		colour;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			if (map->type == TYPE_MANDEL)
				iter = escape_mandelbrot(map_x(mlx, map, x),
						map_y(mlx, map, y), map->max_iter);
			else
				iter = escape_julia(map_x(mlx, map, x),
						map_y(mlx, map, y), map);
			colour = pick_colour(iter, map->max_iter);
			put_pixel(mlx, x, y, colour);
			x++;
		}
		y++;
	}
}

void	put_pixel(t_mlx *mlx, int x, int y, int colour)
{
	int		offset;
	char	*pixel;

	offset = y * mlx->line_length + x * (mlx->bpp / 8);
	pixel = mlx->data_address + offset;
	if (mlx->endian == 0)
	{
		pixel[0] = colour & 0xFF;
		pixel[1] = (colour >> 8) & 0xFF;
		pixel[2] = (colour >> 16) & 0xFF;
	}
	else
	{
		pixel[2] = colour & 0xFF;
		pixel[1] = (colour >> 8) & 0xFF;
		pixel[0] = (colour >> 16) & 0xFF;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:03:31 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/23 13:50:05 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	
	Converts a pixel’s column index in the window into the corresponding
	real‐axis coordinate in the complex‐plane window via linear 
	interpolation.
*/
double	map_x(int x, int width, double x_min, double x_max)
{
	return (x_min + (double)x / (width - 1) * (x_max - x_min));
}

/*
	Converts a pixel’s row index in the window into the corresponding
	imaginary‐axis coordinate in the complex‐plane window via linear 
	interpolation.
*/
double	map_y(int y, int height, double y_min, double y_max)
{
	return (y_min + (double)y / (height - 1) * (y_max - y_min));
}

/*
	Calculates how many iterations the sequence zₙ₊₁ = zₙ² + c stays bounded
	(with |z|² <= 4) before exceeding max_iter. Uses the formula:
		zₙ₊₁ = (zr² – zi² + cr) + i*(2*zr*zi + ci)
	which is is the defining iteration for the classic quadratic fractals:
	Mandelbrot and Julia sets. 
*/
int	escape_iterations(double cr, double ci, int max_iter)
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
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

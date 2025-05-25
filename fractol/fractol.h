/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:08:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/25 16:22:16 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_mlx
{
	void	*mlx_ptr;
	int		width;
	int		height;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_address;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_map
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	cr;
	double	ci;
	int		max_iter;
}	t_map;

/* args.c: Argument validation */
void	check_args(int argc, char **argv, t_map *map);
int		decimals_and_range_check(char *s);
void	print_wrong_args(void);

/* mapping_and_init.c: general mapping representation and */
/* map structure initialization for the different fractals*/
void	mlx_and_img_creation(t_mlx *mlx);
double	map_x(t_mlx *mlx, t_map *map, int x);
double	map_y(t_mlx *mlx, t_map *map, int y);
void	init_mandelbrot(t_map *map);
void	init_julia(int argc, char **argv, t_map *map);

/* rendering.c: functions that decide how */
int		escape_iterations(double zr, double zi, t_map *map);
int		pick_colour(int iter, int max_iter);
void	render(t_mlx *mlx, t_map *map);
void	put_pixel(t_mlx *mlx, int x, int y, int colour);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:08:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/24 17:38:25 by danielm3         ###   ########.fr       */
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
void	check_args(int argc, char **argv);

/* fractol.c: Main coordination for the fractal generation and rendering */
void	mlx_and_img_creation(t_mlx *mlx);
double	map_x(t_mlx *mlx, t_map *map, int x);
double	map_y(t_mlx *mlx, t_map *map, int y);
int		escape_iterations(double zr, double zi, t_map *map);
void	put_pixel(t_mlx *mlx, int x, int y, int colour);

void	init_map_struct(t_map *map);

#endif
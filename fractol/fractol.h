/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 21:08:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/24 12:48:21 by danielm3         ###   ########.fr       */
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

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*data_address;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

/* args.c: Argument validation */
void	check_args(int argc, char **argv);

/* fractol.c: Main coordination for the fractal generation and rendering */
void	put_pixel(char *addr, int x, int y, int colour, int line_len, int bpp);
int		escape_iterations(double c_real, double c_imag, int max_iter);
void	render_fractal(void *mlx, void *win, t_fractal *params);


double	map_x(int x, int width, double x_min, double x_max);
double	map_y(int y, int height, double y_min, double y_max);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:20:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/25 13:45:08 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	check_args(argc, argv, &map);
	mlx_and_img_creation(&mlx);
	render(&mlx, &map);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
/* 

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
	
*/
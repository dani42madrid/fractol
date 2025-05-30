/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:20:30 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/27 23:14:33 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_env	env;

	env.mlx = &mlx;
	env.map = &map;
	check_args(argc, argv, &map);
	mlx_and_img_creation(&mlx);
	render(&mlx, &map);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_mouse_hook(mlx.win_ptr, mouse_zoom, &env);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, on_key_press, &env);
	mlx_hook(mlx.win_ptr, 17, 0L, on_close, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

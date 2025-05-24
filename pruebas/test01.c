/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:26:22 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/24 15:32:38 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Step 1: Open a simple MLX window

Use only what you need to:
- Initialize MLX
- Create a window
- Keep it open

*/

#include "fractol.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*window;
	void	*img_buff;
	
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, 1280, 720, "Me parece haber visto un lindo gatito");
	img_buff = mlx_new_image(mlx_ptr, 1280, 720);
	mlx_loop(mlx_ptr);
	return (0);
}

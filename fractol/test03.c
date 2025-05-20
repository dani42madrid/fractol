/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:41:55 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/20 16:38:04 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Step 3:

- Draw a single red pixel at coordinates (10, 10) using the image 
buffer and the metadata (bpp, line_length, data_address) — no mlx_pixel_put.
- Let me know when you're done.

*/
int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	void	*img_ptr;
	char	*data_address;
	int		bpp;
	int		line_length;
	int		endian;
	
	bpp = 32;
	endian = 0;
	width = 1280;
	height = 720;
	mlx_ptr = mlx_init();
	win_ptr= mlx_new_window(mlx_ptr, width, height, "Me parece haber visto un lindo gatito");
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	data_address = mlx_get_data_addr(img_ptr, &bpp, &line_length, &endian);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
asdasdasdas
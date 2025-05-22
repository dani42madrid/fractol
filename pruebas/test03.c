/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:41:55 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/21 14:05:12 by danielm3         ###   ########.fr       */
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
	height = 1280;
	mlx_ptr = mlx_init();
	win_ptr= mlx_new_window(mlx_ptr, width, height, "fractol (1280 x 1280)");
	img_ptr = mlx_new_image(mlx_ptr, width, height);
	data_address = mlx_get_data_addr(img_ptr, &bpp, &line_length, &endian);
	printf("bpp: %i\n", bpp);
	printf("line_length: %i\n", line_length);
	printf("endian: %i\n", endian);
	put_pixel(data_address, 10, 10, 0xFF0000, line_length, bpp);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}

void	put_pixel(char *addr, int x, int y, int colour, int line_len, int bpp)
{
	int	bypp;
	int	offset;
	(void) colour;
	
	bypp = bpp / 8;
	offset = y * line_len + x * bypp;

	/* orden: blue, green, red, alpha */
	addr[offset + 0] = 0;    // blue
	addr[offset + 1] = 0;    // green
	addr[offset + 2] = (char)0xFF;  // red
	addr[offset + 3] = 0;    // alpha (0 si no usas transparencia)
}

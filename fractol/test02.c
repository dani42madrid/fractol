/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:41:07 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/20 12:41:23 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*window;
	int		width;
	int		height;
	void	*img_buff;
	char	*data_address;
	int		bpp;
	int		line_length;
	int		endian;
	
	bpp = 32;
	endian = 0;
	width = 1280;
	height = 720;
	line_length = width * 4;
	mlx_ptr = mlx_init();
	window = mlx_new_window(mlx_ptr, width, height, "Me parece haber visto un lindo gatito");
	img_buff = mlx_new_image(mlx_ptr, width, height);
	data_address = mlx_get_data_addr(img_buff, &bpp, &line_length, &endian);
	mlx_loop(mlx_ptr);
	return (0);
}
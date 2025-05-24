/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx functions for fractol.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:29:05 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/24 15:34:40 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *mlx_init(void);
// Initializes the MLX library and opens a connection to the X11 display.
// Returns a pointer to the MLX instance, used in all other MLX functions.

void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);
// Creates a new window.
// mlx_ptr: the MLX instance from mlx_init
// width, height: size of the window in pixels
// title: string displayed in the window title bar
// Returns a pointer to the new window.

void *mlx_new_image(void *mlx_ptr, int width, int height);
// Creates a new image in memory to draw on (not visible until shown).
// mlx_ptr: the MLX instance
// width, height: size of the image in pixels
// Returns a pointer to the image object.
// Returns an opaque handle (an internal MLX struct)
// that represents your image. It’s not the raw pixel buffer.

char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *line_length, int *endian);
// Gives access to the image's raw pixel memory buffer.
// img_ptr: the image from mlx_new_image
// bits_per_pixel: pointer to an int that will hold how many bits per pixel (usually 32)
// line_length: pointer to an int that will hold the number of bytes per row (may include padding)
// endian: pointer to an int that will be set to 0 (little-endian) or 1 (big-endian)
// Returns eturns a pointer into that handle’s pixel memory. That pointer typically points 
// to the very first byte of the pixel data, but it’s a different pointer value than the 
// handle itself.

int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
// Displays the image (created and drawn in memory) onto the window.
// mlx_ptr: the MLX instance
// win_ptr: the window where to display the image
// img_ptr: the image to display
// x, y: top-left coordinates in the window where to place the image

int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
// (Slow) Draws a single pixel directly in the window.
// mlx_ptr: the MLX instance
// win_ptr: the window to draw in
// x, y: position of the pixel
// color: the color of the pixel in hexadecimal (e.g. 0xFFFFFF for white)

int mlx_loop(void *mlx_ptr);
// Starts the MLX event loop. This function blocks and keeps the window open.
// mlx_ptr: the MLX instance

int mlx_hook(void *win_ptr, int event, int mask, int (*f)(), void *param);
// Registers a callback function for a window event (like keypress or mouse).
// win_ptr: the window to listen to
// event: the event code (e.g. 2 for keypress)
// mask: the event mask (usually 1L << 0 for keypress)
// f: the function to call when the event happens
// param: a pointer passed to your callback function

int mlx_destroy_window(void *mlx_ptr, void *win_ptr);
// Destroys the given window and frees its resources.
// mlx_ptr: the MLX instance
// win_ptr: the window to destroy

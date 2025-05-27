/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:07:57 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/27 23:15:44 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key(int keycode, void *param)
{
	t_mlx	*mlx;

	if (keycode == XK_Escape)
	{
		mlx = (t_mlx *)param;
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int	on_close(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

int	mouse_zoom(int button, int x, int y, void *param)
{
	t_env	*env;
	double	click_re;
	double	click_im;
	double	zoom_factor;
	double	range;

	env = (t_env *)param;
	if (button != 4 && button != 5)
		return (0);
	if (button == 4)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.1;
	click_re = map_x(env->mlx, env->map, x);
	click_im = map_y(env->mlx, env->map, y);
	range = (env->map->x_max - env->map->x_min) * zoom_factor;
	env->map->x_min = click_re - range / 2;
	env->map->x_max = click_re + range / 2;
	range = (env->map->y_max - env->map->y_min) * zoom_factor;
	env->map->y_min = click_im - range / 2;
	env->map->y_max = click_im + range / 2;
	render(env->mlx, env->map);
	mlx_put_image_to_window(env->mlx->mlx_ptr,
		env->mlx->win_ptr, env->mlx->img_ptr, 0, 0);
	return (0);
}

int	pan_x(int keycode, void *param)
{
	t_env	*env;
	double	shift;

	env = (t_env *)param;
	shift = (env->map->x_max - env->map->x_min) * 0.1;
	if (keycode == XK_Left)
	{
		env->map->x_min -= shift;
		env->map->x_max -= shift;
	}
	else
	{
		env->map->x_min += shift;
		env->map->x_max += shift;
	}
	render(env->mlx, env->map);
	mlx_put_image_to_window(env->mlx->mlx_ptr,
		env->mlx->win_ptr, env->mlx->img_ptr, 0, 0);
	return (0);
}

int	pan_y(int keycode, void *param)
{
	t_env	*env;
	double	shift;

	env = (t_env *)param;
	shift = (env->map->y_max - env->map->y_min) * 0.05;
	if (keycode == XK_Up)
	{
		env->map->y_min -= shift;
		env->map->y_max -= shift;
	}
	else
	{
		env->map->y_min += shift;
		env->map->y_max += shift;
	}
	render(env->mlx, env->map);
	mlx_put_image_to_window(env->mlx->mlx_ptr,
		env->mlx->win_ptr, env->mlx->img_ptr, 0, 0);
	return (0);
}

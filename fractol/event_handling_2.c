/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielm3 <danielm3@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 23:00:26 by danielm3          #+#    #+#             */
/*   Updated: 2025/05/28 13:11:37 by danielm3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key_press(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(env->mlx->mlx_ptr, env->mlx->img_ptr);
		mlx_destroy_window(env->mlx->mlx_ptr, env->mlx->win_ptr);
		mlx_destroy_display(env->mlx->mlx_ptr);
		free(env->mlx->mlx_ptr);
		exit(0);
	}
	if (keycode == XK_Left || keycode == XK_Right)
		return (pan_x(keycode, param));
	if (keycode == XK_Up || keycode == XK_Down)
		return (pan_y(keycode, param));
	return (0);
}

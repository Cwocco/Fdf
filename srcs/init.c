/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 04:13:09 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/18 06:38:38 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int init_windows(t_env *env, int width, int height)
{
	if (!(env->mlx = mlx_init()))
		return (0);
	env->win.win_mlx = mlx_new_window(env->mlx, width, height, "FDF");
	env->img.img_ptr = mlx_new_image(env->mlx, width, height);
	env->img.data = mlx_get_data_addr(env->img.img_ptr, &env->img.bpp, 
		&env->img.size, &env->img.endian);
	mlx_expose_hook(env->win.win_mlx, &xpose_hook, (void *)env);
	mlx_key_hook(env->win.win_mlx, &exit_hook, (void *)env);
	env->win.size.x = width;
	env->win.size.y = height;
//	mlx_mouse_hook(env->win.win_mlx, &hook_mouse, 0);
	return (1);
}

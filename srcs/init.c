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

int init_windows(t_env *env, t_pos size, char *win_name)
{

	env->win.win_mlx = mlx_new_window(env->mlx, size.x, size.y, win_name);
	return (0);
}

int init(t_env *env)
{
	env->mlx = mlx_init();
	return (0);
}



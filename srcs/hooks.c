/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 23:37:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 06:29:49 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include "libft.h"

int				xpose_hook(void *param)
{
	static int	i;
	t_map		*map;
	t_env		*env;

	env = (t_env *)param;
	map = get_map(env->path);
	env->map = map;
	projection_iso(map);
	drawer(env);
	display_img(env);
	if (i)
		del_2dmap(map);
	return (0);
}

int				exit_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == ESC)
		exit(1);
	return (0);
}

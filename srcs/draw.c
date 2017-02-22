/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 04:20:16 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/22 04:20:21 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void drawer(t_env *env)
{
	int			x;
	int			y;
	t_points	**map_pts;

	x = 0;
	map_pts = env->map->points;
	while (x < env->map->width)
	{
		while (y < env->map->height)
		{
			proj->x = (sqrt(2) / 2) * (point->x - point->y);
			proj->y = (sqrt(2 / 3.0) * point->z) - ((1 / sqrt(6)) * (point->x + point->y));
			y++;
		}
		x++;
	}
}
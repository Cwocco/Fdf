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

void normalize_funct(t_points *points, t_env *env)
{
//	v.x = v.x / longueur;
//	v.y = v.y / longueur;
	points->project.x = points->proj.x / (env->map->max.x - env->map->min.x)
	 	* (env->win.size.x);
	points->project.y = points->proj.y / (env->map->max.y - env->map->min.y) 
		* (env->win.size.y);
}

void drawer(t_env *env)
{
	int			x;
	int			y;
	t_points	*map_pts;

	x = 0;
	while (x < env->map->width)
	{
		y = 0;
		while (y < env->map->height)
		{
			map_pts = &env->map->points[y][x];
			normalize_funct(map_pts, env);
			
			y++;
		}
		x++;
	}
}
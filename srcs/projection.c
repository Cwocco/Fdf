/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 03:40:54 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/22 03:41:00 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void get_new_min(t_map *map, t_points *points)
{
	t_2dpos *projx;
	t_2dpos *projy;

	projx = &points->project.x;
	projy = &points->project.y;
	if (points && map)
	{
		map->min.x = projx < map->min.x ? projx : map->min.x;
		map->min.y = projy < map->min.y ? projy : map->min.y;
	}
	else
	{
		map->min.x = projx;
		map->min.y = projy;
	}
}

void get_new_max(t_map *map, t_points *points)
{
	t_2dpos *projx;
	t_2dpos *projy;

	projx = &points->project.x;
	projy = &points->project.y;
	if (points)
	{
		map->max.x = projx > map->max.x ? projx : map->max.x;
		map->max.y = projy > map->min.y ? projy : map->max.y;
	}
	else
	{
		map->max.x = projx;
		map->max.y = projy;
	}
}
void projection_iso(t_map *map)
{
	int			x;
	int			y;
	t_points	*pts;
	t_2dpos		*proj_pts;
	
	x = 0;
	while (x < env->map->width)
	{
		y = 0;
		while (y < env->map->height)
		{

			pts = &map->points[y][x];
			proj_pts = &pts->project;
			proj_pts->x = (sqrt(2) / 2) * (pts->x - pts->y);
			proj_pts->y = (sqrt(2 / 3.0) * pts->z) - ((1 / sqrt(6)) * (pts->x + pts->y));
			get_new_min(map, pts);
			get_new_max(map, pts);
			y++;
		}
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 03:40:54 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 06:34:21 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "get_next_line.h"
#include <math.h>

static void		get_minmax(t_map *map, t_points *points)
{
	t_2dpos		*proj;

	proj = &points->project;
	if (!points->x && !points->y)
	{
		map->min.x = proj->x;
		map->min.y = proj->y;
		map->max.x = proj->x;
		map->max.y = proj->y;
	}
	else
	{
		map->min.x = proj->x < map->min.x ? proj->x : map->min.x;
		map->min.y = proj->y < map->min.y ? proj->y : map->min.y;
		map->max.x = proj->x > map->max.x ? proj->x : map->max.x;
		map->max.y = proj->y > map->max.y ? proj->y : map->max.y;
	}
}

void			projection_iso(t_map *map)
{
	int			x;
	int			y;
	t_points	*pts;
	t_2dpos		*proj_pts;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			pts = &map->points[y][x];
			proj_pts = &pts->project;
			proj_pts->x = (sqrt(2) / 2.0) * (pts->x - pts->y);
			proj_pts->y = (sqrt(2 / 3.0) * -1 * pts->z) - ((1.0 / sqrt(6)) *
				(pts->x + pts->y));
			get_minmax(map, pts);
			y++;
		}
		x++;
	}
}

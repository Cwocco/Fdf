/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 00:10:11 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 00:10:13 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <math.h>
/*
void get_center(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			map->points[y][x].cx += map->width / 2;
			map->points[y][x].cy += map->height / 2;
			y++;
		}
		x++;
	}
}

static void zoom_in(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			map->points[y][x].x -= map->points[y][x].cx;
			map->points[y][x].y -= map->points[y][x].cy;
			map->points[y][x].x *= Z_IN;
			map->points[y][x].y *= Z_IN;
			map->points[y][x].x += map->points[y][x].cx;
			map->points[y][x].y += map->points[y][x].cy;
			y++;
		}
		x++;
	}
}

static void zoom_out(t_map *map)
{
	int x;
	int y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			map->points[y][x].x -= map->points[y][x].cx;
			map->points[y][x].y -= map->points[y][x].cy;
			map->points[y][x].x /= Z_OUT;
			map->points[y][x].y /= Z_OUT;
			map->points[y][x].x += map->points[y][x].cx;
			map->points[y][x].y += map->points[y][x].cy;
			y++;
		}
		x++;
	}
}

void zoom_map(t_env *env, int zoom)
{
	if (zoom == ZOOM_IN)
		zoom_in(env->map);
	else if (zoom == ZOOM_OUT)
		zoom_out(env->map);
}
*/
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
#include <math.h>


static void		put_pixel(t_env *env, t_points *points)
{
	
	int			pts;
	int 		color;

	color = get_color(points->z);
	pts = (floor(points->project.x) * env->img.bpp / 8) +
	 (floor(points->project.y) * env->img.size);
	env->img.data[pts++] =  mlx_get_color_value(env->mlx, color);
	env->img.data[pts++] = mlx_get_color_value(env->mlx, color >> 8);
	env->img.data[pts++] = mlx_get_color_value(env->mlx, color >> 16);
	env->img.data[pts++] = mlx_get_color_value(env->mlx, color >> 20);
}

static void		normalize_funct(t_points *points, t_env *env)
{
//	v.x = v.x / longueur;
//	v.y = v.y / longueur;
	t_2dpos *min;
	t_2dpos *max;
	
	min = &env->map->min;
  	max = &env->map->max;
  	points->project.x = ((points->project.x - min->x) / (max->x - min->x)) * (env->win.size.x - 50);
	points->project.y = ((points->project.y - min->y) / (max->y - min->y)) * (env->win.size.y - 50);
		
}

static void		draw_line(t_env *env, t_points *p1, t_points *p2)
{
	t_2dpos		d;
	t_2dpos		incr;
	t_points	pts;
	int			step;

	d.x = p2->project.x - p1->project.x;
	d.y = p2->project.y - p1->project.y;
	step = fabs(d.x) > fabs(d.y) ? fabs(d.x) : fabs(d.y);
	incr.x = d.x / (float)step;
	incr.y = d.y / (float)step;
	d.x = 0;
	pts = *p1;
	while (d.x++ < step)
	{
		pts.project.x += incr.x;
		pts.project.y += incr.y;
		put_pixel(env, &pts);
	}
}

void			drawer(t_env *env)
{
	int			x;
	int			y;
	t_points	**map_pts;

	map_pts = env->map->points;
	x = 0;
	while (x < env->map->width)
	{
		y = 0;
		while (y < env->map->height)
		{
			normalize_funct(&map_pts[y][x], env);
			put_pixel(env, &map_pts[y][x]);
			if (x > 0)
				draw_line(env, &map_pts[y][x], &map_pts[y][x - 1]);
			if (y > 0)
				draw_line(env, &map_pts[y][x], &map_pts[y - 1][x]);
			y++;
		}
		x++;
	}
}
/*
static void	fdf_put_pixel_img(t_points *point, t_env *env)
{
	int	i;
	int	x;
	int	y;

	if (point->project.x < env->win.size.x
		&& point->project.y < env->win.size.y
		&& point->project.x >= 0
		&& point->project.y >= 0)
	{
		i = 0;
		x = floor(point->project.x) * env->img.bpp / 8;
		y = floor(point->project.y) * env->img.size;
		env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 255);
		env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 255);
		env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 255);
		env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 0);
	}
}

static void	fdf_normalize_point(t_points *point, t_env* env)
{
	t_2dpos	*min;
	t_2dpos	*max;

	min = &env->map->min;
	max = &env->map->max;
	point->project.x = ((((point->project.x - min->x) / (max->x - min->x))) * (env->win.size.x - 1)) - ((min->x - min->x) / (max->x - min->x) * (env->win.size.x- 1));
	point->project.y = (((point->project.y - min->x) / (max->x - min->x))) * (env->win.size.x - 1);
}

static void	fdf_draw_line(t_points *p1, t_points *p2, t_env *env)
{
	int		step;
	t_2dpos	d;
	t_2dpos	incr;
	t_points	point;

	d.x = p2->project.x - p1->project.x;
	d.y = p2->project.y - p1->project.y;
	step = fabs(d.x) > fabs(d.y) ? fabs(d.x) : fabs(d.y);
	incr.x = d.x / (float)step;
	incr.y = d.y / (float)step;
	d.x = 0;
	point = *p1;
	while (d.x++ < step)
	{
		point.project.x += incr.x;
		point.project.y += incr.y;
		fdf_put_pixel_img(&point, env);
	}
}

void	fdf_draw_img(t_env *env)
{
	t_points	**points;
	int		x;
	int		y;

	x = 0;
	points = env->map->points;
	while (x < env->map->width)
	{
		y = 0;
		while (y < env->map->height)
		{
			fdf_normalize_point(&points[y][x], env);
			fdf_put_pixel_img(&points[y][x], env);
			if (x > 0)
				fdf_draw_line(&points[y][x], &points[y][x - 1], env);
			if (y > 0)
				fdf_draw_line(&points[y][x], &points[y - 1][x], env);
			y++;
		}
		x++;
	}
}
 */
void display_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win.win_mlx, env->img.img_ptr, 0, 0);
}
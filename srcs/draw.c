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
/*	int			pts;

	pts = (points->project.x * 4) + (points->project.y * env->img.size);
	env->img.data[pts] = color;
	env->img.data[pts++] = color >> 8;
	env->img.data[pts++] = color >> 16;
*/
	int	i;
	int	x;
	int	y;

	i = 0;
	x = floor(points->project.x) * env->img.bpp / 8;
	y = floor(points->project.y) * env->img.size;
	env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 255);
	env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 255);
	env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 255);
	env->img.data[x + y + i++] = mlx_get_color_value(env->mlx, 0);
}


static void		draw_line(t_env *env, t_points *p1, t_points *p2)
{
	t_2dpos		d;
	t_2dpos		incr;
	t_points	pts;
	int			step;

	d.x = (int)p1->project.x - (int)p2->project.x;
	d.y = p1->project.y - p2->project.y;
	step = fabs(d.x) > fabs(d.y) ? fabs(d.x) : fabs(d.y);
	incr.x = d.x / (float)step;
	incr.y = d.y / (float)step;
	d.x = 0;
	pts = *p1;
	while (d.x < step)
	{
		pts.project.x += incr.x;
		pts.project.y += incr.y;
		put_pixel(env, &pts);
		d.x++;
	}
}


static void		normalize_funct(t_points *points, t_env *env)
{
//	v.x = v.x / longueur;
//	v.y = v.y / longueur;
	t_2dpos *min;
	t_2dpos *max;
	
	min = &env->map->min;
  	max = &env->map->max;
	//points->project.x  = points->project.x / (env->map->max.x - env->map->min.x)
	 //	* (env->win.size.x -1);
  	points->project.x = ((points->project.x - min->y) / (max->y - min->y)) * (env->win.size.y - 1) - ((min->x - min->y) / (max->y - min->y) * (env->win.size.y - 1));
	points->project.y = points->project.y / (env->map->max.y - env->map->min.y) 
		* (env->win.size.y -1);
		
}

void			drawer(t_env *env)
{
	int			x;
	int			y;
	t_points	**map_pts;
//	t_points	*p1;
//	t_points	*p2;

	x = 0;
//	p1 = p1->z_color;
//	p1 = p2->z_color;
	while (x < env->map->width)
	{
		y = 0;
		while (y < env->map->height)
		{
			map_pts = env->map->points;
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

void display_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win.win_mlx, env->img.img_ptr, 0, 0);
}
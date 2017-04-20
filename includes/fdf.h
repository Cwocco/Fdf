/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 01:33:07 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/27 06:27:32 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# define ESC 53

typedef struct	s_2dpos
{
	double		x;
	double		y;
}				t_2dpos;

typedef struct	s_points
{
	double		x;
	double		y;
	double		z;
	int			color;
	t_2dpos		project;
}				t_points;

typedef struct	s_map
{
	t_points	**points;
	int			width;
	int			height;
	t_2dpos		min;
	t_2dpos		max;
}				t_map;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_win
{
	void		*win_mlx;
	t_pos		size;
}				t_win;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			endian;
	int			size;
}				t_img;

typedef struct	s_env
{
	char		*path;
	void		*mlx;
	t_win		win;
	t_map		*map;
	t_img		img;
}				t_env;

int				get_color(int z);
void			fdf_error(int n);
t_map			*get_map(char *path);
int				init_windows(t_env *env, int width, int height, char *win_name);
int				exit_hook(int keycode, void *param);
void			drawer(t_env *env);
void			projection_iso(t_map *map);
void			display_img(t_env *env);
int				xpose_hook(void *param);
void			del_2dmap(t_map *map);

#endif

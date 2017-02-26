/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 01:33:07 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/20 00:53:19 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>

typedef struct s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct s_2dpos
{
	double 		x;
	double		y;
}				t_2dpos;
			
typedef struct s_points
{
	double		x;
	double 		y;
	double 		z;
	int 		color;
	t_2dpos		project;
}				t_points;
            
typedef struct 	s_map
{
	t_points	**points;
	int 		width;
	int 		height;
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

typedef struct 	s_img
{
	void 	*img_ptr; // get addr params
	char	*data; // cuz get addr returns a char*
	int		bpp; // get addr params
	int		endian; // get addr params
	int		size;		 // get addr params
}				t_img;

typedef struct	s_env
{
	//void	*env;
	char	*path;
	void	*mlx;
	t_win	win;
	t_map	*map;
	t_img	img;
	//char	*path;

}				t_env;

int		get_color(int z);
void	fdf_error(int n);
t_map 	*get_map(char *path);
int init_windows(t_env *env, int width, int height);
int 	exit_hook(int keycode, void *param);
void	drawer(t_env *env);
void	projection_iso(t_map *map);
void	display_img(t_env *env);
int 	xpose_hook(void *param);

#endif
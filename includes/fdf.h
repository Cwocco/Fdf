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

typedef struct s_points
{
	int			x;
	int 		y;
	int 		z;
}				t_points;

typedef struct 	s_map
{
	t_points	**points;
	int 		width;
	int 		height;
	int 		len;

}				t_map;

typedef struct	s_pos
{
	int 	x;
	int	 	y;
	int 	z;
}				t_pos;

typedef struct	s_win
{
	void	*win_mlx;
	t_pos	size;
}				t_win;

typedef struct	s_env
{
	void	*env;
	void	*mlx;
	t_win	win;
}				t_env;

void fdf_error(int n);
t_map *create_list(char *path);
#endif

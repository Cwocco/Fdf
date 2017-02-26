/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 20:47:21 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/25 20:47:22 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <fcntl.h>
#include "libft.h"

static void set_map_pts(t_map *map, t_list *list)
{
	int x;
	int y;

	if (!(map->points = (t_points **)malloc(sizeof(t_points *) * map->height)))
		fdf_error(2);
	while (list != NULL)
	{
		if (!(map->points[y] = (t_points *)malloc(sizeof(t_points) * map->width)))
			fdf_error(2);
		y = 0;
		
	}
}
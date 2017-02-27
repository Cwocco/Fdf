/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 00:46:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/02/20 00:55:10 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <fcntl.h>
#include "libft.h"
 
static void		get_map_fromlst(t_map *map, t_list *list)
{
	int			x;
	int			y;

	if (!(map->points = (t_points **)malloc(sizeof(t_points *) * map->height)))
		fdf_error(2);
	y = 0;
	while (list && map)
	{
		if (!(map->points[y] = (t_points *)malloc(sizeof(t_points) * map->width)))
			fdf_error(2);
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = x * 10;
			map->points[y][x].y = y * 10;
			if (!ft_strdigit(((char **)list->content)[0]))
				fdf_error(4);
			map->points[y][x].z = ft_atoi(((char **)list->content)[x]) / 2;
			x++;
		}
		y++;
		list = list->next;
	}
//	free(list);
}

static void		build_map(char *path, int fd, t_map *map)
{
	char		**split;
	t_list		*list;

	map->width	= 0;
	map->height = 0;
	while (get_next_line(fd, &path) > 0)
	{
		split = ft_strsplit(path, ' ');
		ft_strdel(&path);
		if (map->height++ == 0)
		{
			map->width = ptr_strlen(split);
			if (!(list = ft_lstnew(&split, sizeof(char **))))
				fdf_error(2);
			list->content = (void *)split;
		}
		else 
		{
			ft_lstadd(&list, ft_lstnew(&split, sizeof(char **)));
			list->content = (void *)split;
		}
	}
	get_map_fromlst(map, list);
}

t_map		*get_map(char *path)
{
	t_map	*map;
	int		fd;

	if (!(fd = open(path, O_RDONLY)))
		fdf_error(1);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		fdf_error(2);
	build_map(path, fd, map);
	close(fd);
	return (map);
}
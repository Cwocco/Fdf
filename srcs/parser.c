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
#include <fcntl.h>

static t_map *set_point(t_map *map, t_list *list)
{
	int x;
	int y;

	if (!(map->points = (t_points **)malloc(sizeof(t_points *) * map->height)))
		fdf_error(2);
	y = map->height - 1;
	while (list && map)
	{
		if (!(map->points[y] = (t_points *)malloc(sizeof(t_points) * map->width)))
			fdf_error(2);
		x = map->width - 1;
		while (x >= 0)
		{
			map->points[y][x].x = x;
			map->points[y][x].y = y;
			if (!ft_strdigit(((char **)list->content)[x]))
				fdf_error(4);
			map->points[y][x].z = ft_atoi(((char **)list->content)[x]);
			x++;
		}
		y--;
		list = list->next;
	}
	return (map);
}

t_map *create_list(char *path)
{
	char	**split;
	int		fd;
	t_list	*list;
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		fdf_error(2);
	map->height = 0;
	map->width	= 0;
	if (!(fd = open(path, O_RDONLY)))
		fdf_error(1);
	while (get_next_line(fd, &path) > 0)
	{
		split = ft_strsplit(path, ' ');
		ft_strdel(&path);
		if (map->height++ == 0)
		{
			map->width = ptr_strlen(split);
			if (!(list = ft_lstnew(&split, sizeof(char **))))
				fdf_error(2);
		}
		else 
			ft_lstadd(&list, ft_lstnew(&split, sizeof(char **)));
	}
	close(fd);
	return (set_point(map, list));
}
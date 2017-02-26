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
 
static t_map	*get_map_fromlst(t_map *map, t_list *list)
{
	int			x;
	int			y;

	if (!(map->points = (t_points **)malloc(sizeof(t_points *) * map->height)))
		fdf_error(2);
	y = 0;
	while (list && map)
	{
		//ft_putendl(((char **)list->content)[0]);
		if (!(map->points[y] = (t_points *)malloc(sizeof(t_points) * map->width)))
			fdf_error(2);
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = x * 10;
			map->points[y][x].y = y * 10;
			if (!ft_strdigit(((char **)list->content)[x]))
				fdf_error(4);
			map->points[y][x].z = ft_atoi(((char **)list->content)[x]) / 2;
//			ft_putstr(&((char*)list->content)[0]);
			x++;
		}
		y++;
		list = list->next;
	}
	free(list);
	return (map);
}

t_map			*get_map(char *path)
{
	char		**split;
	int			fd;
	t_list		*list;
	t_map		*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		fdf_error(2);
	map->width	= 0;
	map->height = 0;
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
			list->content = (void *)split;
		}
		else 
		{
			ft_lstadd(&list, ft_lstnew(&split, sizeof(char **)));
			list->content = (void *)split;
		}
	}
	close(fd);
	return (get_map_fromlst(map, list));
}

/*
static int	fdf_get_width(char **split)
{
	int i;

	i = 0;
	while (*split++)
		i++;
	return (i);
}

static void	fdf_fill_map(t_map *map, t_list *list)
{
	int		x;
	int		y;

	if (!(map->points = (t_points **)malloc(sizeof(t_points *) * map->height)))
		fdf_error(2);
	y = 0;
	while (list)
	{
		if (!(map->points[y] = (t_points *)malloc(sizeof(t_points) * map->width)))
			fdf_error(2);
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = x;
			map->points[y][x].y = y;
			map->points[y][x].z = ft_atoi(((char **)list->content)[x]);
			x++;
		}
		y++;
		list = list->next;
	}
}

static void	fdf_build_map(int fd, t_map *map)
{
	char	*line;
	char	**split_line;
	t_list	*list;

	map->width = 0;
	map->height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split_line = ft_strsplit(line, ' ');
		free(line);
		if (!map->height)
		{
			map->width = fdf_get_width(split_line);
			list = ft_lstnew(&split_line, sizeof(char **));
			list->content = (void *)split_line;
		}
		else
		{
			// TODO: check errors in file
			ft_lstadd(&list, ft_lstnew(&split_line, sizeof(char **)));
			list->content = (void *)split_line;
		}
		map->height++;
	}
	fdf_fill_map(map, list);
	// TODO: free list
}
t_map	*fdf_get_map(char *path)
{
	int		fd;
	t_map	*map;

	if ((fd = open(path, O_RDONLY)) < 0)
		fdf_error(3);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		fdf_error(2);
	fdf_build_map(fd, map);
	close(fd);
	return (map);
}
*/
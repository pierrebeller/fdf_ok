/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbeller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 09:01:06 by pbeller           #+#    #+#             */
/*   Updated: 2017/03/06 09:01:08 by pbeller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_points	*ft_newpoint(char *data, int y, int index, t_window *win)
{
	t_points *point;

	point = malloc(sizeof(t_points));
	if (point == NULL)
		return (NULL);
	point->x = index;
	point->y = y;
	point->z = ft_atoi(data);
	if (point->z > win->max_z)
		win->max_z = point->z;
	return (point);
}

t_points	**ft_new_line(char *line, int y, t_window *win)
{
	t_points	**bigline;
	char		**tab;
	int			index;

	index = 0;
	bigline = malloc(sizeof(t_points *) * ft_strlen(line) + 1);
	if (bigline == NULL)
		return (NULL);
	tab = ft_strsplit(line, ' ');
	while (tab[index])
	{
		bigline[index] = ft_newpoint(tab[index], y, index, win);
		index++;
	}
	if (index != win->map_w)
		file_error();
	bigline[index] = NULL;
	index = 0;
	while (tab[index])
		free(tab[index++]);
	free(tab);
	return (bigline);
}

t_points	***ft_create_map(t_list *map, t_window *win)
{
	t_points	***tab;
	char		**tmp;
	int			y;

	y = 0;
	tmp = ft_strsplit(map->content, ' ');
	win->map_w = ft_length(tmp);
	ft_destroy(tmp);
	tab = malloc(sizeof(t_points **) * ft_lstlen(map) + 1);
	if (tab == NULL)
		return (NULL);
	while (map)
	{
		if (map->content == NULL || ft_strlen(map->content) == 0)
			break ;
		tab[y] = ft_new_line(map->content, y, win);
		y++;
		map = map->next;
	}
	win->map_h = y;
	tab[y] = NULL;
	return (tab);
}

t_list		*ft_create_list(int fd, char *line, t_list *map)
{
	int gnl;
	int i;

	i = 0;
	while (1)
	{
		gnl = get_next_line(fd, &line);
		if (gnl == -1 || i >= 2000)
			file_error();
		if (gnl == 0)
			break ;
		ft_lst_push_back(&map, ft_lstnew(line, ft_strlen(line)));
		free(line);
		i++;
	}
	free(line);
	return (map);
}

t_points	***ft_fdf(t_window *win)
{
	int			fd;
	char		*line;
	t_list		*map;
	t_points	***tab;

	fd = open(win->path, O_RDONLY);
	if (fd < 0)
		file_error();
	line = ft_strdup("");
	map = NULL;
	map = ft_create_list(fd, line, map);
	tab = ft_create_map(map, win);
	ft_lstdel(&map, del);
	free(map);
	close(fd);
	return (tab);
}

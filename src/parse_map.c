/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:11:58 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 14:18:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_number_lines(char *str, t_all *a)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str == ';')
			a->map.n++;
		str++;
	}
}

void	get_max_map_len(char **map, t_all *a)
{
	int y;
	int x;

	if (!map)
		return ;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > a->map.x)
			a->map.x = x;
		y++;
	}
	a->map.y = y;
}

int		malloc_map(char **map, t_all *a)
{
	int	y;
	int	x;

	a->map.tab = malloc(sizeof(char *) * (a->map.y + 1));
	if (!a->map.tab)
		return (a->errnum = 2);
	y = -1;
	while (++y < a->map.y)
	{
		a->map.tab[y] = malloc(sizeof(char) * (a->map.x + 1));
		if (!a->map.tab[y])
			return (a->errnum = 2);
		x = -1;
		while (map[y][++x])
			a->map.tab[y][x] = map[y][x];
		while (x < a->map.x)
			a->map.tab[y][x++] = ' ';
		a->map.tab[y][x] = '\0';
	}
	a->map.tab[y] = 0;
	return (a->errnum);
}

int		complete_map(char *s, t_all *a)
{
	char	**map;

	get_number_lines(s, a);
	map = ft_split(s, ';');
	if (map)
		get_max_map_len(map, a);
	if (map == NULL || a->map.n != a->map.y)
	{
		if (map)
			free_tab(map);
		return (a->errnum = 17);
	}
	malloc_map(map, a);
	free_tab(map);
	return (a->errnum);
}

int		parse_map(int fd, char *line, t_all *a)
{
	char	*s;
	char	*buf;
	int		ret;
	char	*tmp;

	ret = get_next_line(fd, &buf);
	if (ret == 0)
	{
		free(buf);
		return (a->errnum = 9);
	}
	s = join_map_lines("", line);
	while (ret > 0)
	{
		tmp = s;
		s = join_map_lines(tmp, buf);
		free(buf);
		free(tmp);
		tmp = NULL;
		ret = get_next_line(fd, &buf);
	}
	complete_map(s, a);
	free_tmp(buf, tmp, s);
	check_map(a->map.tab, a);
	return (a->errnum);
}

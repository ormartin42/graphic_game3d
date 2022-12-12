/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:11:51 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 14:21:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_map_zeros(char **map, t_all *a)
{
	int y;
	int x;

	y = 0;
	while (y < a->map.y - 1)
	{
		x = 0;
		while (++x < a->map.x - 1)
		{
			if (map[y][x] == '0')
			{
				if (!ft_strchr("012NSWE", map[y - 1][x])
						|| !ft_strchr("012NSWE", map[y - 1][x - 1])
						|| !ft_strchr("012NSWE", map[y - 1][x + 1])
						|| !ft_strchr("012NSWE", map[y][x - 1])
						|| !ft_strchr("012NSWE", map[y][x + 1])
						|| !ft_strchr("012NSWE", map[y + 1][x - 1])
						|| !ft_strchr("012NSWE", map[y + 1][x + 1]))
					return (a->errnum = 9);
			}
		}
		y++;
	}
	return (a->errnum);
}

int	check_map_spaces(char **map, t_all *a)
{
	int y;
	int x;

	y = 1;
	while (y < a->map.y - 1)
	{
		x = 0;
		while (++x < a->map.x - 1)
		{
			if (map[y][x] == ' ')
			{
				if (!ft_strchr("1 ", map[y - 1][x])
						|| !ft_strchr("1 ", map[y - 1][x - 1])
						|| !ft_strchr("1 ", map[y - 1][x + 1])
						|| !ft_strchr("1 ", map[y][x - 1])
						|| !ft_strchr("1 ", map[y][x + 1])
						|| !ft_strchr("1 ", map[y + 1][x])
						|| !ft_strchr("1 ", map[y + 1][x + 1])
						|| !ft_strchr("1 ", map[y + 1][x - 1]))
					return (a->errnum = 9);
			}
		}
		y++;
	}
	return (a->errnum);
}

int	check_map_borders2(char **map, t_all *a)
{
	int	y;
	int	x;

	y = 0;
	x = a->map.x - 1;
	while (map[++y] && y < a->map.y - 1)
	{
		if (map[y][x] == '0' || map[y][x] == '2')
		{
			if (!ft_strchr("1 ", map[y - 1][x])
				|| !ft_strchr("1 ", map[y + 1][x])
				|| !ft_strchr("1 ", map[y - 1][x - 1])
				|| !ft_strchr("1 ", map[y + 1][x - 1])
				|| !ft_strchr("1 ", map[y][x - 1]))
				return (a->errnum = 9);
		}
	}
	return (a->errnum);
}

int	check_map_borders1(char **map, t_all *a)
{
	int y;
	int x;

	x = -1;
	while (map[0][++x])
		if (!ft_strchr("1 ", map[0][x]))
			return (a->errnum = 9);
	y = a->map.y - 1;
	x = -1;
	while (map[y][++x])
		if (!ft_strchr("1 ", map[y][x]))
			return (a->errnum = 9);
	y = 0;
	x = 0;
	while (map[++y] && y < a->map.y - 1)
	{
		if (map[y][x] == '0' || map[y][x] == '2')
			if (!ft_strchr("1 ", map[y - 1][x])
				|| !ft_strchr("1 ", map[y + 1][x])
				|| !ft_strchr("1 ", map[y - 1][x + 1])
				|| !ft_strchr("1 ", map[y + 1][x + 1])
				|| !ft_strchr("1 ", map[y][x + 1]))
				return (a->errnum = 9);
	}
	return (a->errnum);
}

int	check_map(char **map, t_all *a)
{
	if (a->errnum)
		return (a->errnum);
	if (check_map_borders1(map, a)
		|| check_map_borders2(map, a)
		|| check_map_spaces(map, a)
		|| check_map_zeros(map, a))
		return (a->errnum);
	if (parse_pos(map, a)
		|| parse_sprites(map, a))
		return (a->errnum);
	a->map.valid_map++;
	return (1);
}

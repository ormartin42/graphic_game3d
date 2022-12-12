/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:06 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 14:01:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_dir(t_all *a)
{
	if (a->play.dir == 'N')
	{
		a->play.dirx = 0;
		a->play.diry = -1;
		a->play.planx = 0.66;
		a->play.plany = 0;
	}
	else if (a->play.dir == 'S')
	{
		a->play.dirx = 0;
		a->play.diry = 1;
		a->play.planx = -0.66;
		a->play.plany = 0;
	}
	else if (a->play.dir == 'E')
	{
		a->play.dirx = 1;
		a->play.diry = 0;
	}
	else if (a->play.dir == 'W')
	{
		a->play.dirx = -1;
		a->play.diry = 0;
		a->play.plany = -0.66;
	}
}

int		check_pos(char **map, int x, int y, t_all *a)
{
	if (!ft_strchr("012", map[y - 1][x])
		|| !ft_strchr("012", map[y - 1][x - 1])
		|| !ft_strchr("012", map[y - 1][x + 1])
		|| !ft_strchr("012", map[y][x - 1])
		|| !ft_strchr("012", map[y][x + 1])
		|| !ft_strchr("012", map[y + 1][x - 1])
		|| !ft_strchr("012", map[y + 1][x + 1]))
		return (a->errnum = 9);
	return (1);
}

int		parse_pos(char **map, t_all *a)
{
	int	y;
	int	x;

	y = 0;
	while (map[++y] && y < a->map.y - 1)
	{
		x = 0;
		while (map[y][++x] && x < a->map.x - 1)
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				if (a->play.x != -1 || a->play.y != -1)
					return (a->errnum = 7);
				if (check_pos(map, x, y, a) != 1)
					return (a->errnum);
				a->play.x = (double)x + 0.5;
				a->play.y = (double)y + 0.5;
				a->play.dir = map[y][x];
				map[y][x] = '0';
				get_dir(a);
			}
		}
	}
	return (a->errnum);
}

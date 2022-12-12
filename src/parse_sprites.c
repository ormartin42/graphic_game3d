/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:22 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 11:45:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_sprites(char **map, t_all *a)
{
	int y;
	int x;

	a->rspr.spr_nb = 0;
	y = 0;
	while (map[++y] && y < a->map.y - 1)
	{
		x = 0;
		while (map[y][++x] && x < a->map.x - 1)
		{
			if (map[y][x] == '2')
			{
				if (a->rspr.spr_nb >= MAX_NB_SPR)
					return (a->errnum = 12);
				a->spr[a->rspr.spr_nb].x = (double)x + 0.5;
				a->spr[a->rspr.spr_nb].y = (double)y + 0.5;
				a->rspr.spr_nb++;
			}
		}
	}
	return (a->errnum);
}

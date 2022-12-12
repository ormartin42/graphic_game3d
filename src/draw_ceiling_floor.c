/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:11 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:10:14 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_ceiling_floor(t_all *a)
{
	int	y;
	int	x;

	y = -1;
	while (++y < a->res.y / 2)
	{
		x = -1;
		while (++x < a->res.x)
			a->img.addr[y * a->img.bpl + x] = a->col.c;
	}
	y--;
	while (++y < a->res.y)
	{
		x = -1;
		while (++x < a->res.x)
			a->img.addr[y * a->img.bpl + x] = a->col.f;
	}
}

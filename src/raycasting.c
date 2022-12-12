/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:43 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 08:22:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_step_side_dist(t_all *a)
{
	if (a->ray.dirx < 0)
	{
		a->ray.stx = -1;
		a->ray.sdx = (a->play.x - a->ray.mapx) * a->ray.ddx;
	}
	else
	{
		a->ray.stx = 1;
		a->ray.sdx = (a->ray.mapx + 1.0 - a->play.x) * a->ray.ddx;
	}
	if (a->ray.diry < 0)
	{
		a->ray.sty = -1;
		a->ray.sdy = (a->play.y - a->ray.mapy) * a->ray.ddy;
	}
	else
	{
		a->ray.sty = 1;
		a->ray.sdy = (a->ray.mapy + 1.0 - a->play.y) * a->ray.ddy;
	}
}

void	dda(int x, t_all *a)
{
	while (a->ray.hit == 0)
	{
		if (a->ray.sdx < a->ray.sdy)
		{
			a->ray.sdx += a->ray.ddx;
			a->ray.mapx += a->ray.stx;
			a->ray.side = 0;
		}
		else
		{
			a->ray.sdy += a->ray.ddy;
			a->ray.mapy += a->ray.sty;
			a->ray.side = 1;
		}
		if (a->map.tab[a->ray.mapy][a->ray.mapx] == '1')
			a->ray.hit = 1;
	}
	if (a->ray.side == 0)
		a->ray.ppwd = (a->ray.mapx - a->play.x + (1 - a->ray.stx) / 2)
		/ a->ray.dirx;
	else
		a->ray.ppwd = (a->ray.mapy - a->play.y + (1 - a->ray.sty) / 2)
		/ a->ray.diry;
	a->rspr.zb[x] = a->ray.ppwd;
}

void	raycasting(t_all *a)
{
	int	x;

	x = 0;
	a->rspr.zb = malloc(sizeof(double) * a->res.x);
	if (!a->rspr.zb)
		error(a->errnum = 2, a);
	while (x < a->res.x && !a->errnum)
	{
		a->ray.hit = 0;
		a->ray.ppwd = 0;
		a->ray.camx = 2 * x / (double)a->res.x - 1;
		a->ray.dirx = a->play.dirx + a->play.planx * a->ray.camx;
		a->ray.diry = a->play.diry + a->play.plany * a->ray.camx;
		a->ray.mapx = (int)a->play.x;
		a->ray.mapy = (int)a->play.y;
		a->ray.ddx = fabs(1 / a->ray.dirx);
		a->ray.ddy = fabs(1 / a->ray.diry);
		get_step_side_dist(a);
		dda(x, a);
		draw_texture(x, a);
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:20 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:10:23 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_draw_start_end(t_all *a)
{
	a->ray.lh = (int)(a->res.y / a->ray.ppwd);
	a->ray.draws = -(a->ray.lh) / 2 + a->res.y / 2;
	if (a->ray.draws < 0)
		a->ray.draws = 0;
	a->ray.drawe = a->ray.lh / 2 + a->res.y / 2;
	if (a->ray.drawe >= a->res.y)
		a->ray.drawe = a->res.y - 1;
	if (a->ray.side == 0)
		a->ray.wallx = a->play.y + a->ray.ppwd * a->ray.diry;
	else
		a->ray.wallx = a->play.x + a->ray.ppwd * a->ray.dirx;
	a->ray.wallx -= floor(a->ray.wallx);
	a->ray.tx = (int)(a->ray.wallx * (double)64);
	if (a->ray.side == 0 && a->ray.dirx > 0)
		a->ray.tx = 64 - a->ray.tx - 1;
	if (a->ray.side == 1 && a->ray.diry < 0)
		a->ray.tx = 64 - a->ray.tx - 1;
	a->ray.tstep = 1.0 * 64 / a->ray.lh;
	a->ray.tpos = (a->ray.draws - a->res.y / 2 + a->ray.lh / 2) * a->ray.tstep;
}

void	draw_texture(int x, t_all *a)
{
	get_draw_start_end(a);
	while (a->ray.draws < a->ray.drawe)
	{
		a->ray.ty = (int)a->ray.tpos & (64 - 1);
		a->ray.tpos += a->ray.tstep;
		if (a->ray.dirx >= 0 && !a->ray.side)
			a->img.addr[a->ray.draws * a->img.bpl + x] =
			a->text.et[a->ray.ty * 64 + a->ray.tx];
		if (a->ray.dirx < 0 && !a->ray.side)
			a->img.addr[a->ray.draws * a->img.bpl + x] =
			a->text.wt[a->ray.ty * 64 + a->ray.tx];
		if (a->ray.diry >= 0 && a->ray.side)
			a->img.addr[a->ray.draws * a->img.bpl + x] =
			a->text.nt[a->ray.ty * 64 + a->ray.tx];
		if (a->ray.diry < 0 && a->ray.side)
			a->img.addr[a->ray.draws * a->img.bpl + x] =
			a->text.st[a->ray.ty * 64 + a->ray.tx];
		a->ray.draws++;
	}
}

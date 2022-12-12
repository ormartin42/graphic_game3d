/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:52 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:12:53 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_sprite(t_ray_spr *spr, t_all *a)
{
	int stripe;
	int y;

	stripe = spr->drawsx;
	while (stripe < spr->drawex)
	{
		spr->texx = (int)(256 * (stripe - (-spr->width / 2 + spr->screenx))
			* 64 / spr->width) / 256;
		if (spr->transfy > 0 && stripe > 0 && stripe < a->res.x
			&& spr->transfy < spr->zb[stripe])
		{
			y = spr->drawsy;
			while (y < spr->drawey)
			{
				spr->d = (y) * 256 - a->res.y * 128 + spr->height * 128;
				spr->texy = ((spr->d * 64) / spr->height) / 256;
				if (a->text.spt[spr->texy * 64 + spr->texx] != 0)
					a->img.addr[y * a->img.bpl + stripe] =
					a->text.spt[spr->texy * 64 + spr->texx];
				y++;
			}
		}
		stripe++;
	}
}

void	sprite_draw_info(int *order, t_ray_spr *spr, int i, t_all *a)
{
	spr->x = a->spr[order[i]].x - a->play.x;
	spr->y = a->spr[order[i]].y - a->play.y;
	spr->invdet = 1.0 / (a->play.planx * a->play.diry
		- a->play.dirx * a->play.plany);
	spr->transfx = spr->invdet *
		(a->play.diry * spr->x - a->play.dirx * spr->y);
	spr->transfy = spr->invdet *
		(-a->play.plany * spr->x + a->play.planx * spr->y);
	spr->screenx = (int)((a->res.x / 2) * (1 + spr->transfx / spr->transfy));
	spr->height = abs((int)(a->res.y / spr->transfy));
	spr->drawsy = -spr->height / 2 + a->res.y / 2;
	if (spr->drawsy < 0)
		spr->drawsy = 0;
	spr->drawey = spr->height / 2 + a->res.y / 2;
	if (spr->drawey >= a->res.y)
		spr->drawey = a->res.y - 1;
	spr->width = abs((int)(a->res.y / spr->transfy));
	spr->drawsx = -spr->width / 2 + spr->screenx;
	if (spr->drawsx < 0)
		spr->drawsx = 0;
	spr->drawex = spr->width / 2 + spr->screenx;
	if (spr->drawex >= a->res.x)
		spr->drawex = a->res.x - 1;
}

void	sort_sprites(int *order, double *dist, int nb)
{
	int		i;
	int		j;
	double	tmpd;
	int		tmpo;

	j = 0;
	while (j < nb)
	{
		i = 0;
		while (i < nb)
		{
			if (dist[i] < dist[j])
			{
				tmpd = dist[i];
				dist[i] = dist[j];
				dist[j] = tmpd;
				tmpo = order[i];
				order[i] = order[j];
				order[j] = tmpo;
			}
			i++;
		}
		j++;
	}
}

void	raycast_sprites(int spr_nb, t_all *a)
{
	int		spr_order[spr_nb];
	double	spr_dist[spr_nb];
	int		i;

	i = -1;
	while (++i < spr_nb)
	{
		spr_order[i] = i;
		spr_dist[i] = ((a->play.x - a->spr[i].x) * (a->play.x - a->spr[i].x)
			+ (a->play.y - a->spr[i].y) * (a->play.y - a->spr[i].y));
	}
	sort_sprites(spr_order, spr_dist, spr_nb);
	i = -1;
	while (++i < spr_nb)
	{
		sprite_draw_info(spr_order, &a->rspr, i, a);
		draw_sprite(&a->rspr, a);
	}
}

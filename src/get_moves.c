/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:56 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:10:58 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate(t_all *a)
{
	double olddirx;
	double oldplanx;

	if (a->move.rl)
	{
		olddirx = a->play.dirx;
		a->play.dirx = a->play.dirx * cos(-RS) - a->play.diry * sin(-RS);
		a->play.diry = olddirx * sin(-RS) + a->play.diry * cos(-RS);
		oldplanx = a->play.planx;
		a->play.planx = a->play.planx * cos(-RS) - a->play.plany * sin(-RS);
		a->play.plany = oldplanx * sin(-RS) + a->play.plany * cos(-RS);
	}
	if (a->move.rr)
	{
		olddirx = a->play.dirx;
		a->play.dirx = a->play.dirx * cos(RS) - a->play.diry * sin(RS);
		a->play.diry = olddirx * sin(RS) + a->play.diry * cos(RS);
		oldplanx = a->play.planx;
		a->play.planx = a->play.planx * cos(RS) - a->play.plany * sin(RS);
		a->play.plany = oldplanx * sin(RS) + a->play.plany * cos(RS);
	}
}

void	move_lft_rght(t_all *a)
{
	if (a->move.lft)
	{
		if (a->map.tab[(int)floor(a->play.y)]
			[(int)floor(a->play.x - a->play.planx * MS)] == '0')
			a->play.x -= a->play.planx * MS;
		if (a->map.tab[(int)floor(a->play.y - a->play.plany * MS)]
			[(int)floor(a->play.x)] == '0')
			a->play.y -= a->play.plany * MS;
	}
	if (a->move.rght)
	{
		if (a->map.tab[(int)floor(a->play.y)]
			[(int)floor(a->play.x + a->play.planx * MS)] == '0')
			a->play.x += a->play.planx * MS;
		if (a->map.tab[(int)floor(a->play.y + a->play.plany * MS)]
			[(int)floor(a->play.x)] == '0')
			a->play.y += a->play.plany * MS;
	}
}

void	move_fwd_bck(t_all *a)
{
	if (a->move.fwd)
	{
		if (a->map.tab[(int)floor(a->play.y)]
			[(int)floor(a->play.x + a->play.dirx * MS)] == '0')
			a->play.x += a->play.dirx * MS;
		if (a->map.tab[(int)floor(a->play.y + a->play.diry * MS)]
			[(int)floor(a->play.x)] == '0')
			a->play.y += a->play.diry * MS;
	}
	if (a->move.bck)
	{
		if (a->map.tab[(int)floor(a->play.y)]
			[(int)floor(a->play.x - a->play.dirx * MS)] == '0')
			a->play.x -= a->play.dirx * MS;
		if (a->map.tab[(int)floor(a->play.y - a->play.diry * MS)]
			[(int)floor(a->play.x)] == '0')
			a->play.y -= a->play.diry * MS;
	}
}

void	get_moves(t_all *a)
{
	if (a->move.esc)
		exit_game(a);
	if (a->move.fwd || a->move.bck)
		move_fwd_bck(a);
	if (a->move.lft || a->move.rght)
		move_lft_rght(a);
	if (a->move.rl || a->move.rr)
		rotate(a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:11:15 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:11:19 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_all *a)
{
	if (key == W)
		a->move.fwd = 1;
	else if (key == S)
		a->move.bck = 1;
	else if (key == A)
		a->move.lft = 1;
	else if (key == D)
		a->move.rght = 1;
	else if (key == LEFT_ARROW)
		a->move.rl = 1;
	else if (key == RIGHT_ARROW)
		a->move.rr = 1;
	else if (key == ESC)
		a->move.esc = 1;
	return (0);
}

int	key_release(int key, t_all *a)
{
	if (key == W)
		a->move.fwd = 0;
	else if (key == S)
		a->move.bck = 0;
	else if (key == A)
		a->move.lft = 0;
	else if (key == D)
		a->move.rght = 0;
	else if (key == LEFT_ARROW)
		a->move.rl = 0;
	else if (key == RIGHT_ARROW)
		a->move.rr = 0;
	else if (key == ESC)
		a->move.esc = 0;
	return (0);
}

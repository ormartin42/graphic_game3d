/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:11:06 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 09:00:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_player(t_all *a)
{
	a->play.x = -1;
	a->play.y = -1;
	a->play.dir = '\0';
	a->play.dirx = 0;
	a->play.diry = 0;
	a->play.planx = 0;
	a->play.plany = 0.66;
}

void	init_struct(t_all *a)
{
	a->cub_file = 0;
	a->save = 0;
	a->errnum = 0;
	a->cub_info = NULL;
	ft_memset(&a->res, 0, sizeof(t_resolution));
	ft_memset(&a->col, 0, sizeof(t_colors));
	ft_memset(&a->text, 0, sizeof(t_textures));
	ft_memset(&a->map, 0, sizeof(t_map));
	ft_memset(&a->move, 0, sizeof(t_moves));
	ft_memset(&a->mlx, 0, sizeof(t_mlx));
	ft_memset(&a->img, 0, sizeof(t_img));
	ft_memset(&a->rspr, 0, sizeof(t_ray_spr));
	ft_memset(&a->spr, 0, sizeof(t_sprite));
	ft_memset(&a->ray, 0, sizeof(t_ray));
	init_player(a);
}

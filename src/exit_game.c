/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:48 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 09:21:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	close_game(t_all *a)
{
	mlx_destroy_image(a->mlx.ptr, a->text.n_img);
	mlx_destroy_image(a->mlx.ptr, a->text.s_img);
	mlx_destroy_image(a->mlx.ptr, a->text.e_img);
	mlx_destroy_image(a->mlx.ptr, a->text.w_img);
	mlx_destroy_image(a->mlx.ptr, a->text.spt_img);
	free_tab(a->map.tab);
	free(a);
	exit(0);
	return (1);
}

int	exit_game(t_all *a)
{
	if (a->img.ptr)
		mlx_destroy_image(a->mlx.ptr, a->img.ptr);
	if (a->text.n_img)
		mlx_destroy_image(a->mlx.ptr, a->text.n_img);
	if (a->text.s_img)
		mlx_destroy_image(a->mlx.ptr, a->text.s_img);
	if (a->text.w_img)
		mlx_destroy_image(a->mlx.ptr, a->text.w_img);
	if (a->text.e_img)
		mlx_destroy_image(a->mlx.ptr, a->text.e_img);
	if (a->text.spt_img)
		mlx_destroy_image(a->mlx.ptr, a->text.spt_img);
	if (a->mlx.win)
		mlx_destroy_window(a->mlx.ptr, a->mlx.win);
	if (a->mlx.ptr)
		free(a->mlx.ptr);
	if (a->rspr.zb)
		free(a->rspr.zb);
	if (a->map.tab)
		free_tab(a->map.tab);
	free(a);
	exit(0);
	return (1);
}

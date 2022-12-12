/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:01 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 11:17:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	init_game(t_all *a)
{
	a->img.ptr = mlx_new_image(a->mlx.ptr, a->res.x, a->res.y);
	if (!a->img.ptr)
		return (a->errnum = 18);
	a->img.addr = (int *)mlx_get_data_addr(a->img.ptr, &a->img.bpp,
		&a->img.bpl, &a->img.end);
	a->img.bpl /= 4;
	draw_ceiling_floor(a);
	raycasting(a);
	raycast_sprites(a->rspr.spr_nb, a);
	get_moves(a);
	if (!a->save)
	{
		mlx_put_image_to_window(a->mlx.ptr, a->mlx.win, a->img.ptr, 0, 0);
		mlx_destroy_image(a->mlx.ptr, a->img.ptr);
		free(a->rspr.zb);
	}
	return (1);
}

int	init_loop(t_all *a)
{
	int resx;
	int resy;

	resx = 0;
	resy = 0;
	mlx_get_screen_size(a->mlx.ptr, &resx, &resy);
	if (a->res.x > resx && !a->save)
		a->res.x = resx;
	if (a->res.y > resy && !a->save)
		a->res.y = resy;
	a->mlx.win = mlx_new_window(a->mlx.ptr, a->res.x, a->res.y, "cub3D");
	if (!a->mlx.win)
		return (error(a->errnum = 19, a));
	mlx_hook(a->mlx.win, 2, 1L << 0, key_press, a);
	mlx_loop_hook(a->mlx.ptr, init_game, a);
	mlx_hook(a->mlx.win, 3, 1L << 1, key_release, a);
	mlx_hook(a->mlx.win, 33, 1L << 17, close_game, a);
	mlx_loop(a->mlx.ptr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_all	*a;

	if (argc == 2 || argc == 3)
	{
		a = NULL;
		a = (t_all *)malloc(sizeof(t_all));
		if (!a)
			return (error3());
		init_struct(a);
		if ((check_arg_cub(argv[1], a))
			|| (argc == 3 && check_arg_save(argv[2], a)))
			return (error(a->errnum, a));
		a->mlx.ptr = mlx_init();
		if (!a->mlx.ptr)
			return (error(a->errnum = 13, a));
		if (parse_info(argv[1], a) != 1)
			return (error(a->errnum, a));
		if (a->save)
			bmp(a);
		init_loop(a);
	}
	printf("Error\nWrong number of arguments");
	return (0);
}

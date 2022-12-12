/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:09:28 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 11:49:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_struct_bmp(t_bmp *bmp, t_all *a)
{
	int resx;
	int resy;

	resx = 0;
	resy = 0;
	mlx_get_screen_size(a->mlx.ptr, &resx, &resy);
	if (a->res.x > resx)
		a->res.x = resx;
	if (a->res.y > resy)
		a->res.y = resy;
	bmp->size = 54 + 4 * a->res.x * a->res.y;
	bmp->zero = 0;
	bmp->offset = 54;
	bmp->headbytes = 40;
	bmp->plane = 1;
	bmp->bpp = 32;
}

void	write_header_bmp(int fd, t_bmp *bmp, t_all *a)
{
	write(fd, "BM", 2);
	write(fd, &bmp->size, 4);
	write(fd, &bmp->zero, 2);
	write(fd, &bmp->zero, 2);
	write(fd, &bmp->offset, 4);
	write(fd, &bmp->headbytes, 4);
	write(fd, &a->res.x, 4);
	write(fd, &a->res.y, 4);
	write(fd, &bmp->plane, 2);
	write(fd, &bmp->bpp, 2);
	write(fd, &bmp->zero, 4);
	write(fd, &bmp->zero, 4);
	write(fd, &bmp->zero, 4);
	write(fd, &bmp->zero, 4);
	write(fd, &bmp->zero, 4);
	write(fd, &bmp->zero, 4);
}

void	write_image_bmp(int fd, t_all *a)
{
	int	y;
	int	x;

	init_game(a);
	y = a->res.y + 1;
	while (0 <= --y)
	{
		x = -1;
		while (++x < a->res.x)
			write(fd, &a->img.addr[y * a->img.bpl + x], 4);
	}
}

int		bmp(t_all *a)
{
	int		fd;
	t_bmp	*bmp;

	bmp = NULL;
	bmp = (t_bmp*)malloc(sizeof(t_bmp));
	if (!bmp)
		return (a->errnum = 2);
	init_struct_bmp(bmp, a);
	fd = open("save.bmp", O_WRONLY | O_CREAT, S_IRWXU | O_TRUNC);
	if (fd < 0)
	{
		free(bmp);
		return (error(a->errnum = 14, a));
	}
	write_header_bmp(fd, bmp, a);
	write_image_bmp(fd, a);
	close(fd);
	free(bmp);
	bmp = NULL;
	exit_game(a);
	return (0);
}

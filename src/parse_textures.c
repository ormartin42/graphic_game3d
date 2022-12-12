/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:31 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 13:05:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	stack_texture(char *line, void **img, int **xpm, t_all *a)
{
	int		fd;
	int		len;
	int		tab[5];
	char	c;

	len = ft_strlen(line);
	if (len < 6)
		return (a->errnum = 11);
	if (ft_strcmp(".xpm", &line[len - 4])
		|| (!ft_strcmp(".xpm", &line[len - 4]) && !&line[len - 5]))
		return (a->errnum = 11);
	if ((fd = open(line, O_RDONLY)) < 0)
		return (a->errnum = 20);
	if (read(fd, &c, 0) == -1)
		return (a->errnum = 16);
	close(fd);
	*img = mlx_xpm_file_to_image(a->mlx.ptr, line, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		a->errnum = 11;
	if (!a->errnum)
	{
		*xpm = (int *)mlx_get_data_addr(*img, &tab[2], &tab[3], &tab[4]);
		a->text.valid_text++;
	}
	return (a->errnum);
}

int	parse_texture(char *line, void **img, int **xpm, t_all *a)
{
	char	*tmp;

	if (*xpm)
		return (a->errnum = 7);
	tmp = ft_strtrim(line, " ");
	stack_texture(tmp, img, xpm, a);
	free(tmp);
	tmp = NULL;
	return (a->errnum);
}

int	parse_textures(char *line, t_all *a)
{
	if (!ft_strncmp("NO ", line, 3))
		parse_texture(&line[3], &a->text.n_img, &a->text.nt, a);
	else if (!ft_strncmp("SO ", line, 3))
		parse_texture(&line[3], &a->text.s_img, &a->text.st, a);
	else if (!ft_strncmp("EA ", line, 3))
		parse_texture(&line[3], &a->text.e_img, &a->text.et, a);
	else if (!ft_strncmp("WE ", line, 3))
		parse_texture(&line[3], &a->text.w_img, &a->text.wt, a);
	else if (!ft_strncmp("S ", line, 2))
		parse_texture(&line[2], &a->text.spt_img, &a->text.spt, a);
	else
		return (a->errnum = 8);
	return (1);
}

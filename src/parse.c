/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:11:26 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 08:54:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_info(t_all *a)
{
	if (a->text.valid_text != 5 || a->col.valid_col != 2
		|| !a->res.valid_res || !a->map.valid_map
			|| !a->play.dir)
		return (a->errnum = 6);
	return (0);
}

int	parse_line(char *line, t_all *a)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R' && line[i + 1] == ' ')
		parse_resolution(line, a);
	else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		parse_textures(line, a);
	else if (line[i] == 'C' || line[i] == 'F')
		parse_colors(line, a);
	else if (line[i] == '\0' || line[i] == '\n')
		;
	else
		a->errnum = 8;
	return (a->errnum);
}

int	read_info(char *cub_file, t_all *a)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(cub_file, O_RDONLY);
	if (fd < 0)
		return (a->errnum = 5);
	ret = get_next_line(fd, &line);
	if (ret == 0)
		a->errnum = 10;
	while (ret > 0 && !is_map(line) && !a->errnum)
	{
		if (parse_line(line, a) != 0)
			break ;
		free(line);
		line = NULL;
		ret = get_next_line(fd, &line);
	}
	if (!a->errnum && !is_map(line))
		a->errnum = 15;
	else if (!a->errnum && ret > 0)
		parse_map(fd, line, a);
	close(fd);
	free(line);
	return (a->errnum);
}

int	parse_info(char *cub_file, t_all *a)
{
	if (read_info(cub_file, a) != 0)
		return (a->errnum);
	if (check_info(a) != 0)
		return (a->errnum);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:11:36 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 08:33:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_color(int red, int green, int blue, t_all *a)
{
	if (red > 255 || red < 0 || green > 255 || green < 0
			|| blue > 255 || blue < 0)
		return (a->errnum = 8);
	return (1);
}

int	check_comas(char *line, t_all *a)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (line[++i])
	{
		if (line[i] == ',')
		{
			if (i == 0 || (!ft_isdigit(line[i - 1])
				&& !ft_isdigit(line[i + 1])))
				return (a->errnum = 8);
			c++;
		}
	}
	if (c != 2)
		return (a->errnum = 8);
	return (1);
}

int	stack_color(char **str, int *color, t_all *a)
{
	int	r;
	int	g;
	int	b;

	if (a->errnum)
		error(a->errnum, a);
	r = -1;
	while (str[++r] && !a->errnum)
	{
		g = -1;
		while (str[r][++g] && !a->errnum)
		{
			if (!ft_isdigit(str[r][g]))
				return (a->errnum = 8);
		}
	}
	r = ft_atoi(str[0]);
	g = ft_atoi(str[1]);
	b = ft_atoi(str[2]);
	if (check_color(r, g, b, a) != 1)
		return (a->errnum = 8);
	*color = (r * 256 * 256) + (g * 256) + b;
	a->col.valid_col++;
	return (1);
}

int	parse_color(char *line, int *color, t_all *a)
{
	char	*tmp;
	char	**str;
	int		i;

	if (*color)
		return (a->errnum = 7);
	tmp = skip_spaces(line);
	if (*color || !tmp)
		error(a->errnum = 2, a);
	if (check_comas(tmp, a) != 1)
	{
		free(tmp);
		tmp = NULL;
		return (a->errnum);
	}
	str = ft_split(tmp, ',');
	free(tmp);
	i = 0;
	while (str[i])
		i++;
	if (i != 3)
		a->errnum = 6;
	stack_color(str, color, a);
	free_tab(str);
	return (a->errnum);
}

int	parse_colors(char *line, t_all *a)
{
	if (line[0] == 'C' && line[1] == ' ')
		parse_color(&line[2], &a->col.c, a);
	else if (line[0] == 'F' && line[1] == ' ')
		parse_color(&line[2], &a->col.f, a);
	else
		a->errnum = 8;
	if (a->errnum)
		return (a->errnum);
	return (1);
}

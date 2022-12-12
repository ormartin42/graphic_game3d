/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:12:13 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 09:56:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	stack_resolution(char **str, t_all *a)
{
	a->res.x = ft_atoi(str[0]);
	a->res.y = ft_atoi(str[1]);
	if (a->res.x <= 0 || a->res.y <= 0)
		return (a->errnum = 8);
	a->res.valid_res++;
	return (1);
}

int	parse_resolution(char *line, t_all *a)
{
	char	**str;
	int		i;

	i = 1;
	while (line[++i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (a->errnum = 8);
	}
	str = ft_split(&line[2], ' ');
	i = 0;
	while (str[i])
		i++;
	if (i != 2)
	{
		free_tab(str);
		return (a->errnum = 6);
	}
	stack_resolution(str, a);
	free_tab(str);
	return (a->errnum);
}

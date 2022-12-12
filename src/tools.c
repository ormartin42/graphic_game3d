/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:13:00 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 08:34:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_tmp(char *s1, char *s2, char *s3)
{
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	free(s3);
	s3 = NULL;
}

void	free_tab(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	str = NULL;
}

char	*skip_spaces(char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (line[i] == ' ')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		if (line[i] != ' ')
		{
			new[j] = line[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

int		is_map(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

char	*join_map_lines(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i++] = ';';
	s3[i] = '\0';
	return (s3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:09:46 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:09:48 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_arg_cub(char *cub, t_all *a)
{
	int	len;
	int	fd;

	a->cub_file = 0;
	len = ft_strlen(cub);
	if (len < 5)
		return (a->errnum = 23);
	if (!ft_strncmp(&cub[len - 4], ".cub", 5))
	{
		fd = open(cub, O_DIRECTORY);
		if (fd != -1)
			return (a->errnum = 16);
		if (fd >= 0)
			close(fd);
		a->cub_file = 1;
		return (0);
	}
	return (a->errnum = 21);
}

int	check_arg_save(char *save, t_all *a)
{
	if (!ft_strncmp(save, "--save", 7))
	{
		a->save = 1;
		return (0);
	}
	return (a->errnum = 21);
}

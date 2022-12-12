/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:10:35 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/23 18:10:36 by ormartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		error3(void)
{
	printf("Error\nMalloc error.");
	return (0);
}

void	error2(int errnum)
{
	if (errnum == 12)
		printf("Error\nTo many sprites.");
	else if (errnum == 13)
		printf("Error\nMlx init failed.");
	else if (errnum == 14)
		printf("Error\nCould not create bmp file.");
	else if (errnum == 15)
		printf("Error\nMap is missing.");
	else if (errnum == 16)
		printf("Error\n.cub file is a directory.");
	else if (errnum == 17)
		printf("Error\nMap is not at the end of the file.");
	else if (errnum == 18)
		printf("Error\nCould not create mlx image.");
	else if (errnum == 19)
		printf("Error\nCould not create mlx window.");
	else if (errnum == 20)
		printf("Error\nCould not open texture.");
	else if (errnum == 21)
		printf("Error\nWrong argument.");
	else if (errnum == 22)
		printf("Error\nInvalid .cub file name.");
}

int		error(int errnum, t_all *a)
{
	if (errnum == 2)
		printf("Error\nMalloc error.");
	else if (errnum == 3)
		printf("Error\nWrong number arguments.");
	else if (errnum == 4)
		printf("Error\nWrong type of file(s).");
	else if (errnum == 5)
		printf("Error\nError opening file(s).");
	else if (errnum == 6)
		printf("Error\nInformation missing.");
	else if (errnum == 7)
		printf("Error\nSame information twice.");
	else if (errnum == 8)
		printf("Error\nInvalid information was found while parsing .cub file.");
	else if (errnum == 9)
		printf("Error\nMap is not valid.");
	else if (errnum == 10)
		printf("Error\nEmpty .cub file.");
	else if (errnum == 11)
		printf("Error\nInvalid .xpm file.");
	else
		error2(errnum);
	exit_game(a);
	return (0);
}

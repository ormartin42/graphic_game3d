/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ormartin <ormartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:09:28 by ormartin          #+#    #+#             */
/*   Updated: 2021/03/24 14:02:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define W 119
# define S 115
# define D 100
# define A 97
# define ESC 65307

# define MS 0.07
# define RS 0.06

# define TILE 16

# define BPL 256
# define BPP 32

# define MAX_NB_SPR 100

typedef struct	s_resolution
{
	int			x;
	int			y;
	int			valid_res;
}				t_resolution;

typedef struct	s_textures
{
	void		*n_img;
	void		*s_img;
	void		*w_img;
	void		*e_img;
	void		*spt_img;
	int			*nt;
	int			*st;
	int			*wt;
	int			*et;
	int			*spt;
	int			valid_text;
}				t_textures;

typedef struct	s_colors
{
	int			f;
	int			c;
	int			valid_col;
}				t_colors;

typedef struct	s_map
{
	char		**tab;
	int			x;
	int			y;
	int			n;
	int			valid_map;
}				t_map;

typedef struct	s_player
{
	double		x;
	double		y;
	char		dir;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
}				t_player;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

typedef	struct	s_img
{
	void		*ptr;
	int			*addr;
	int			bpp;
	int			bpl;
	int			end;
}				t_img;

typedef	struct	s_moves
{
	int			esc;
	int			fwd;
	int			bck;
	int			lft;
	int			rght;
	int			rl;
	int			rr;
}				t_moves;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		camx;
	int			mapx;
	int			mapy;
	double		sdx;
	double		sdy;
	double		ddx;
	double		ddy;
	double		ppwd;
	int			stx;
	int			sty;
	int			hit;
	int			side;
	int			draws;
	int			drawe;
	int			lh;
	double		wallx;
	int			tx;
	int			ty;
	double		tstep;
	double		tpos;
}				t_ray;

typedef struct	s_sprite
{
	double		x;
	double		y;
}				t_sprite;

typedef struct	s_ray_spr
{
	double		*zb;
	int			spr_nb;
	double		x;
	double		y;
	double		invdet;
	double		transfx;
	double		transfy;
	int			screenx;
	int			height;
	int			drawsy;
	int			drawey;
	int			width;
	int			drawsx;
	int			drawex;
	int			texx;
	int			texy;
	int			d;
}				t_ray_spr;

typedef struct	s_bmp
{
	int			fd;
	int			size;
	int			zero;
	int			offset;
	int			headbytes;
	int			plane;
	int			bpp;
}				t_bmp;

typedef struct	s_all
{
	t_resolution	res;
	t_textures		text;
	t_colors		col;
	t_map			map;
	t_player		play;
	t_mlx			mlx;
	t_img			img;
	t_ray			ray;
	t_moves			move;
	t_sprite		spr[MAX_NB_SPR];
	t_ray_spr		rspr;
	int				errnum;
	int				save;
	int				cub_file;
	char			*cub_info;
}				t_all;

/*
** CUB3D.C
*/

int				main(int argc, char **argv);
int				init_loop(t_all *a);
int				init_game(t_all *a);

/*
** INIT_STRUCT.C
*/

void			init_struct(t_all *a);
void			init_player(t_all *a);

/*
** CHECK_ARGS.C
*/

int				check_arg_cub(char *cub, t_all *a);
int				check_arg_save(char *save, t_all *a);

/*
** PARSE.C
*/

int				parse_info(char *cub_file, t_all *a);
int				read_info(char *cub_file, t_all *a);
int				parse_line(char *line, t_all *a);
int				check_info(t_all *a);

/*
**  PARSE_RESOLUTION.C
*/

int				parse_resolution(char *line, t_all *a);
int				stack_resolution(char **str, t_all *a);

/*
**  PARSE_COLORS.C
*/

int				parse_colors(char *line, t_all *a);
int				parse_color(char *line, int *color, t_all *a);
int				check_comas(char *line, t_all *a);
int				stack_color(char **str, int *color, t_all *a);
int				check_color(int red, int green, int blue, t_all *a);

/*
** PARSE_TEXTURES.C
*/

int				parse_textures(char *line, t_all *a);
int				parse_texture(char *line, void **img, int **xpm, t_all *a);
int				stack_texture(char *line, void **img, int **xpm, t_all *a);

/*
** PARSE_MAP.C
*/

int				parse_map(int fd, char *line, t_all *a);
int				complete_map(char *s, t_all *a);
int				malloc_map(char **map, t_all *a);
void			get_number_lines(char *str, t_all *a);
void			get_max_map_len(char **map, t_all *a);

/*
** CHECK_MAP.C
*/

int				check_map(char **map, t_all *a);
int				check_map_borders1(char **map, t_all *a);
int				check_map_borders2(char **map, t_all *a);
int				check_map_spaces(char **map, t_all *a);
int				check_map_zeros(char **map, t_all *a);

/*
** PARSE_POS.C
*/

int				parse_pos(char **map, t_all *a);
int				check_pos(char **map, int x, int y, t_all *a);
void			get_dir(t_all *a);

/*
** PARSE_SPRITES.C
*/

int				parse_sprites(char **map, t_all *a);

/*
** KEY_MANAGER.C
*/

int				key_press(int key, t_all *a);
int				key_release(int key, t_all *a);

/*
**  GET_MOVES.C
*/

void			get_moves(t_all *a);
void			move_fwd_bck(t_all *a);
void			move_lft_rght(t_all *a);
void			rotate(t_all *a);

/*
** RAYCASTING.C
*/

void			raycasting(t_all *a);
void			dda(int x, t_all *a);
void			get_step_side_dist(t_all *a);

/*
** DRAW_CEILING_FLOOR.C
*/

void			draw_ceiling_floor(t_all *a);

/*
** DRAW_WALL_TEXTURES.C
*/

void			draw_texture(int x, t_all *a);
void			get_draw_start_end(t_all *a);

/*
** RAYCASTING_SPRITES.C
*/

void			raycast_sprites(int spr_nb, t_all *a);
void			sort_sprites(int *order, double *dist, int nb);
void			sprite_draw_info(int *order, t_ray_spr *spr, int i, t_all *a);
void			draw_sprite(t_ray_spr *spr, t_all *a);

/*
** BMP.C
*/

int				bmp(t_all *a);
void			init_struct_bmp(t_bmp *bmp, t_all *a);
void			write_header_bmp(int fd, t_bmp *bmp, t_all *a);
void			write_image_bmp(int fd, t_all *a);

/*
** TOOLS.C
*/

void			free_tmp(char *s1, char *s2, char *s3);
void			free_tab(char **str);
char			*skip_spaces(char *line);
int				is_map(char *line);
char			*join_map_lines(char *s1, char *s2);

/*
** EXIT_GAME.C
*/

int				exit_game(t_all *a);
int				close_game(t_all *a);

/*
** ERRORS.C
*/

int				error(int errnum, t_all *a);
void			error2(int errnum);
int				error3(void);

#endif

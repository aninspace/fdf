/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:26:24 by fmelda            #+#    #+#             */
/*   Updated: 2019/07/18 16:37:47 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define DEG2RAD			(M_PI / 180.f)
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))

# define TEXT_COLOR			0xEAEAEA
# define HEIGHT				1080
# define WIDTH				1920
# define MENU_WIDTH			250

# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

typedef struct	s_xyz
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_xyz;

typedef struct	s_map
{
	int			height;
	int			width;
}				t_map;

typedef struct	s_ugol
{
	int			zoom;
	int			x_offset;
	int			y_offset;
	int			projection;
	float		z_changer;
	float		ugol_x;
	float		ugol_y;
	float		ugol_z;
}				t_ugol;

typedef struct	s_input
{
	int			x;
	int			y;
	int			i;
	int			check;
	char		**space;
	int			fd;
	char		*line;
	char		**comma;
}				t_input;

typedef struct	s_fdf
{
	int			x;
	int			y;
}				t_fdf;

typedef struct	s_mlx
{
	void		*ptr_mlx;
	void		*win_mlx;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			max;
	int			min;
	t_xyz		*xyz;
	t_map		map;
	t_ugol		ugol;
	t_input		input;
	t_fdf		fdf;
}				t_mlx;

t_mlx			write_coordinates(char **argv);
void			risuem_linii(t_mlx *mlx);
void			ft_cleanarr(char **arr);
int				count_nb(char **str);
int				get_color(t_xyz current, t_xyz start, t_xyz end, t_xyz delta);
t_xyz			get_nearest_lower(t_mlx *mlx, t_xyz *current);
t_xyz			get_nearest_higher(t_mlx *mlx, t_xyz *current);
void			print_menu(t_mlx *fdf);
void			color_xyz(t_mlx *mlx);
void			zoom(int key, t_mlx *mlx);
void			move(int key, t_mlx *mlx);
void			turn(int key, t_mlx *mlx);
void			change_z(int key, t_mlx *mlx);
void			change_projection(int key, t_mlx *mlx);
void			rotate_x(int *y, int *z, float ugol);
void			rotate_y(int *x, int *z, float ugol);
void			rotate_z(int *x, int *y, float ugol);
void			iso(int *x, int *y, int z);
t_xyz			prepare_xyz(t_xyz xyz, t_mlx *mlx);
int				key_press(int key, void *param);
int				get_default_color(int z, t_mlx *mlx);
void			gorizontal(t_mlx *mlx);
void			draw_line(t_xyz f, t_xyz s, t_mlx *fdf);
void			get_maxmin(t_mlx *mlx);
void			set_color(t_mlx *mlx);

#endif

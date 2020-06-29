/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 16:58:07 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/18 16:05:13 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		put_pixel(t_mlx *fdf, int x, int y, int color)
{
	int			i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->bits_per_pixel / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void			draw_line(t_xyz f, t_xyz s, t_mlx *fdf)
{
	t_xyz		delta;
	t_xyz		sign;
	t_xyz		cur;
	int			error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, f, s, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void		draw_background(t_mlx *fdf)
{
	int			*image;
	int			i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
		i++;
	}
}

void			vertical(t_mlx *mlx)
{
	draw_line(prepare_xyz(mlx->xyz[mlx->fdf.x + mlx->fdf.y *
	mlx->map.width], mlx), prepare_xyz(mlx->xyz[mlx->fdf.x +
	(mlx->fdf.y + 1) * mlx->map.width], mlx), mlx);
}

void			risuem_linii(t_mlx *mlx)
{
	draw_background(mlx);
	mlx->fdf.y = 0;
	while (mlx->fdf.y < mlx->map.height)
	{
		mlx->fdf.x = 0;
		while (mlx->fdf.x < (mlx->map.width - 1))
		{
			gorizontal(mlx);
			mlx->fdf.x++;
		}
		mlx->fdf.y++;
	}
	mlx->fdf.y = 0;
	while (mlx->fdf.y < (mlx->map.height - 1))
	{
		mlx->fdf.x = 0;
		while (mlx->fdf.x < mlx->map.width)
		{
			vertical(mlx);
			mlx->fdf.x++;
		}
		mlx->fdf.y++;
	}
	mlx_put_image_to_window(mlx->ptr_mlx, mlx->win_mlx, mlx->img, 0, 0);
	print_menu(mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:33:12 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/18 16:12:49 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double		percent(int start, int end, int current)
{
	double	placement;
	double	distance;
	double	percentage;

	placement = current - start;
	distance = end - start;
	percentage = (fabs(placement) / fabs(distance));
	return ((distance == 0) ? 1.0 : percentage);
}

int			get_default_color(int z, t_mlx *mlx)
{
	double	percentage;

	percentage = percent(mlx->min, mlx->max, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int			get_color(t_xyz current, t_xyz start, t_xyz end, t_xyz delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
					(end.color >> 16) & 0xFF,
					percentage);
	green = get_light((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF,
					percentage);
	blue = get_light(start.color & 0xFF,
					end.color & 0xFF,
					percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		gorizontal(t_mlx *mlx)
{
	draw_line(prepare_xyz(mlx->xyz[mlx->fdf.x + mlx->fdf.y *
	mlx->map.width], mlx), prepare_xyz(mlx->xyz[mlx->fdf.x +
	1 + mlx->fdf.y * mlx->map.width], mlx), mlx);
}

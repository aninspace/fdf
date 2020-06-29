/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:16:45 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/18 17:13:12 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(int *y, int *z, float ugol)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(ugol * DEG2RAD) - *z * sin(ugol * DEG2RAD);
	*z = previous_y * sin(ugol * DEG2RAD) + *z * cos(ugol * DEG2RAD);
}

void	rotate_y(int *x, int *z, float ugol)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(ugol * DEG2RAD) + *z * sin(ugol * DEG2RAD);
	*z = -previous_x * sin(ugol * DEG2RAD) + *z * cos(ugol * DEG2RAD);
}

void	rotate_z(int *x, int *y, float ugol)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(ugol * DEG2RAD) - previous_y * sin(ugol * DEG2RAD);
	*y = previous_x * sin(ugol * DEG2RAD) + previous_y * cos(ugol * DEG2RAD);
}

void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_xyz	prepare_xyz(t_xyz xyz, t_mlx *mlx)
{
	xyz.x = xyz.x * mlx->ugol.zoom;
	xyz.y = xyz.y * mlx->ugol.zoom;
	xyz.z = (xyz.z * mlx->ugol.zoom) / mlx->ugol.z_changer;
	rotate_x(&xyz.y, &xyz.z, mlx->ugol.ugol_x);
	rotate_y(&xyz.x, &xyz.z, mlx->ugol.ugol_y);
	rotate_z(&xyz.x, &xyz.y, mlx->ugol.ugol_z);
	if (mlx->ugol.projection == 1)
		iso(&xyz.x, &xyz.y, xyz.z);
	xyz.x += (WIDTH - MENU_WIDTH) / 2 + mlx->ugol.x_offset + MENU_WIDTH;
	xyz.y += (HEIGHT + mlx->map.height * mlx->ugol.zoom) / 2
												+ mlx->ugol.y_offset;
	return (xyz);
}

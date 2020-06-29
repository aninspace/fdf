/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_changes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:56:24 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/18 04:11:40 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys_define.h"

void	zoom(int key, t_mlx *mlx)
{
	if (key == NUM_PAD_PLUS)
		mlx->ugol.zoom++;
	else if (key == NUM_PAD_MINUS)
		mlx->ugol.zoom--;
	if (mlx->ugol.zoom < 1)
		mlx->ugol.zoom = 1;
	mlx_clear_window(mlx->ptr_mlx, mlx->win_mlx);
	risuem_linii(mlx);
}

void	move(int key, t_mlx *mlx)
{
	if (key == ARROW_UP)
		mlx->ugol.y_offset -= 10;
	else if (key == ARROW_DOWN)
		mlx->ugol.y_offset += 10;
	else if (key == ARROW_RIGHT)
		mlx->ugol.x_offset += 10;
	else if (key == ARROW_LEFT)
		mlx->ugol.x_offset -= 10;
	mlx_clear_window(mlx->ptr_mlx, mlx->win_mlx);
	risuem_linii(mlx);
}

void	turn(int key, t_mlx *mlx)
{
	if (key == NUM_X_LEFT)
		mlx->ugol.ugol_x -= 5;
	else if (key == NUM_X_RIGHT)
		mlx->ugol.ugol_x += 5;
	else if (key == NUM_Y_LEFT)
		mlx->ugol.ugol_y -= 5;
	else if (key == NUM_Y_RIGHT)
		mlx->ugol.ugol_y += 5;
	else if (key == NUM_Z_LEFT)
		mlx->ugol.ugol_z -= 5;
	else if (key == NUM_Z_RIGHT)
		mlx->ugol.ugol_z += 5;
	mlx_clear_window(mlx->ptr_mlx, mlx->win_mlx);
	risuem_linii(mlx);
}

void	change_z(int key, t_mlx *mlx)
{
	if (key == Z_UP)
		mlx->ugol.z_changer -= 0.1;
	else if (key == Z_DOWN)
		mlx->ugol.z_changer += 0.1;
	if (mlx->ugol.z_changer < 0.1)
		mlx->ugol.z_changer = 0.1;
	else if (mlx->ugol.z_changer > 5)
		mlx->ugol.z_changer = 5;
	mlx_clear_window(mlx->ptr_mlx, mlx->win_mlx);
	risuem_linii(mlx);
}

void	change_projection(int key, t_mlx *mlx)
{
	mlx->ugol.ugol_x = 0;
	mlx->ugol.ugol_y = 0;
	mlx->ugol.ugol_z = 0;
	if (key == PARALLEL_PROJECTION)
		mlx->ugol.projection = 0;
	else if (key == ISO_PROJECTION)
		mlx->ugol.projection = 1;
	mlx_clear_window(mlx->ptr_mlx, mlx->win_mlx);
	risuem_linii(mlx);
}

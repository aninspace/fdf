/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:47:15 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/18 04:19:21 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys_define.h"

int			key_press(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (key == ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zoom(key, mlx);
	else if (key == ARROW_UP || key == ARROW_DOWN
			|| key == ARROW_LEFT || key == ARROW_RIGHT)
		move(key, mlx);
	else if (key == NUM_X_LEFT || key == NUM_X_RIGHT
			|| key == NUM_Y_LEFT || key == NUM_Y_RIGHT
			|| key == NUM_Z_LEFT || key == NUM_Z_RIGHT)
		turn(key, mlx);
	else if (key == Z_DOWN || key == Z_UP)
		change_z(key, mlx);
	else if (key == ISO_PROJECTION || key == PARALLEL_PROJECTION)
		change_projection(key, mlx);
	return (0);
}

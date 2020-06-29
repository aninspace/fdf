/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 18:10:06 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/19 15:33:42 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			cross_close(void *param)
{
	(void)param;
	exit(0);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		mlx = write_coordinates(argv);
		mlx.ugol = (t_ugol){0, 0, 0, 1, 1, 0, 0, 0};
		mlx.ugol.zoom = FT_MIN(((WIDTH - MENU_WIDTH) / mlx.map.width) / 2,
												(HEIGHT / mlx.map.height) / 2);
		get_maxmin(&mlx);
		set_color(&mlx);
		mlx.ptr_mlx = mlx_init();
		mlx.win_mlx = mlx_new_window(mlx.ptr_mlx, WIDTH, HEIGHT, "FdF");
		mlx.img = mlx_new_image(mlx.ptr_mlx, WIDTH, HEIGHT);
		mlx.data_addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
		&mlx.size_line, &mlx.endian);
		risuem_linii(&mlx);
		mlx_hook(mlx.win_mlx, 17, (1L << 17), cross_close, &mlx);
		mlx_hook(mlx.win_mlx, 2, 0, &key_press, &mlx);
		mlx_loop(mlx.ptr_mlx);
	}
	else
		ft_putstr("Error. Please choose a map from maps/ .");
	return (0);
}

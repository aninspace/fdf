/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxmin_getter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhulk <rhulk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 15:48:15 by rhulk             #+#    #+#             */
/*   Updated: 2019/07/18 16:09:57 by rhulk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_maxmin(t_mlx *mlx)
{
	int	i;
	int	max;
	int	min;

	max = mlx->xyz[0].z;
	min = mlx->xyz[0].z;
	i = 0;
	while (i < mlx->map.height * mlx->map.width)
	{
		if (mlx->xyz[i].z < min)
			min = mlx->xyz[i].z;
		if (mlx->xyz[i].z > max)
			max = mlx->xyz[i].z;
		i++;
	}
	mlx->max = max;
	mlx->min = min;
}

void	set_color(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->map.height * mlx->map.width)
	{
		if (mlx->xyz[i].color == 0x000000)
			mlx->xyz[i].color = get_default_color(mlx->xyz[i].z, mlx);
		i++;
	}
}

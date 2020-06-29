/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:23:49 by fmelda            #+#    #+#             */
/*   Updated: 2019/07/19 15:19:55 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			count_nb(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		mnogo(t_xyz *arr, t_input *all)
{
	if (all->comma[0])
	{
		arr[all->i].x = all->x++;
		arr[all->i].y = all->y;
		if (is_number(all->comma[0]))
			arr[all->i].z = ft_atoi_base(all->comma[0], 10);
		else
		{
			ft_putstr("Error. Please choose a map from maps/ .");
			exit(1);
		}
	}
}

void		delete_comma(t_xyz *arr, t_input *all)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (all->space[i])
	{
		all->comma = ft_strsplit(all->space[i], ',');
		mnogo(arr, all);
		if (all->comma[1])
		{
			if (all->comma[1][j] == '0' && all->comma[1][j + 1] == 'x')
				arr[all->i].color = ft_atoi_base(all->comma[1], 16);
			else
			{
				ft_putstr("Error. Please choose a map from maps/ .");
				exit(1);
			}
		}
		else
			arr[all->i].color = 0x000000;
		ft_cleanarr(all->comma);
		i++;
		all->i += 1;
	}
}

void		slishkom_mnogo_strok(t_mlx *mlx)
{
	while (get_next_line(mlx->input.fd, &mlx->input.line) > 0)
	{
		mlx->input.space = ft_strsplit(mlx->input.line, ' ');
		if (mlx->input.check != 0
			&& mlx->input.check != count_nb(mlx->input.space))
		{
			ft_putstr("Error. Please choose a map from maps/ .");
			exit(1);
		}
		mlx->map.width = count_nb(mlx->input.space);
		mlx->map.height++;
		mlx->input.check = count_nb(mlx->input.space);
		if (mlx->input.line)
			free(mlx->input.line);
		ft_cleanarr(mlx->input.space);
	}
}

t_mlx		write_coordinates(char **argv)
{
	t_mlx mlx;

	mlx.map.height = 0;
	mlx.input.check = 0;
	mlx.input.i = 0;
	mlx.input.fd = open(argv[1], O_RDONLY);
	slishkom_mnogo_strok(&mlx);
	close(mlx.input.fd);
	mlx.input.fd = open(argv[1], O_RDONLY);
	mlx.input.x = -(mlx.map.width / 2);
	mlx.input.y = -(mlx.map.height / 2);
	mlx.xyz = (t_xyz *)malloc(sizeof(t_xyz) * mlx.map.width * mlx.map.height);
	while (get_next_line(mlx.input.fd, &mlx.input.line) > 0)
	{
		mlx.input.space = ft_strsplit(mlx.input.line, ' ');
		delete_comma(mlx.xyz, &mlx.input);
		mlx.input.x = -(mlx.map.width / 2);
		mlx.input.y++;
		ft_cleanarr(mlx.input.space);
		free(mlx.input.line);
	}
	return (mlx);
}

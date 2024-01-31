/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:45 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:20:40 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_data *data)
{
	if (key == UP_A || key == UP_B)
		move_up(data);
	if (key == DOWN_A || key == DOWN_B)
		move_down(data);
	if (key == LEFT_A || key == LEFT_B)
		move_left(data);
	if (key == RIGHT_A || key == RIGHT_B)
		move_right(data);
	if (key == ESC)
		mlx_stop(data, 0);
	return (0);
}

int	mlx_go(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (error(ERR_MLX, data), 1);
	data->win = mlx_new_window(data->mlx, I_S * data->w, I_S * data->h, "SL");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (error(ERR_MLX, data), 1);
	}
	data->mlx_status = 1;
	file_to_img(data, I_S);
	map_render(data);
	mlx_key_hook(data->win, key_pressed, data);
	mlx_hook(data->win, 17, 0L, mlx_stop, data);
	mlx_loop(data->mlx);
	return (0);
}

int	mlx_stop(t_data *data, int status)
{
	free_img(data);
	printf("GOOD BYE!!!\n");
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_data_map(data);
	free(data->mlx);
	exit(status);
	return (0);
}

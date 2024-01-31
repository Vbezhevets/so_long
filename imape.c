/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:04 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:18:04 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_img(t_data *data, int s)
{
	data->i.i_wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &s, &s);
	if (!data->i.i_wall)
		error(ERR_IMG, data);
	data->i.i_score = mlx_xpm_file_to_image(data->mlx, "img/score.xpm", &s, &s);
	if (!data->i.i_score)
		error(ERR_IMG, data);
	data->i.i_space = mlx_xpm_file_to_image(data->mlx, "img/space.xpm", &s, &s);
	if (!data->i.i_space)
		error(ERR_IMG, data);
	data->i.i_move1 = mlx_xpm_file_to_image(data->mlx, "img/move1.xpm", &s, &s);
	if (!data->i.i_move1)
		error(ERR_IMG, data);
	data->i.i_move2 = mlx_xpm_file_to_image(data->mlx, "img/move2.xpm", &s, &s);
	if (!data->i.i_move2)
		error(ERR_IMG, data);
	data->i.i_move3 = mlx_xpm_file_to_image(data->mlx, "img/move3.xpm", &s, &s);
	if (!data->i.i_move3)
		error(ERR_IMG, data);
	data->i.i_move4 = mlx_xpm_file_to_image(data->mlx, "img/move4.xpm", &s, &s);
	if (!data->i.i_move4)
		error(ERR_IMG, data);
	data->i.i_exit = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm", &s, &s);
	if (!data->i.i_exit)
		error(ERR_IMG, data);
}

void	*get_img(t_data *data, char c)
{
	int	s;

	s = I_S;
	if (c == WALL)
		return (data->i.i_wall);
	if (c == SCORE)
		return (data->i.i_score);
	if (c == SPACE)
		return (data->i.i_space);
	if (c == PLAYER)
	{
		if (data->dir == 1)
			return (data->i.i_move1);
		if (data->dir == 2)
			return (data->i.i_move2);
		if (data->dir == 3)
			return (data->i.i_move3);
		if (data->dir == 4)
			return (data->i.i_move4);
	}
	if (c == EXIT)
		return (data->i.i_exit);
	return (data->i.i_exit);
}

int	map_render(t_data *data)
{
	int		y;
	int		x;
	void	*i_temp;

	x = 0;
	y = 0;
	i_temp = NULL;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			i_temp = get_img(data, data->map[y][x]);
			if (!i_temp)
				return (error(ERR_IMG, data), 1);
			mlx_put_image_to_window
			(data->mlx, data->win, i_temp, x * I_S, y * I_S);
			x++;
		}
		y++;
	}
	return (0);
}

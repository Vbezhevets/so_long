/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_and_frees.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:22:57 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:41:52 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	f_mp(char **map, int h)
{
	while (h >= 0)
	{
		if (map[h] != NULL)
		{
			free(map[h]);
			map[h] = NULL;
		}
		h--;
	}
}

void	free_data_map(t_data *data)
{
	if (data->map)
	{
		if (data->h > 0)
		{
			f_mp(data->map, data->h - 1);
			data->h = 0;
		}
		free(data->map);
	}
}

void	free_img(t_data *data)
{
	if (data->i.i_wall)
		mlx_destroy_image(data->mlx, data->i.i_wall);
	if (data->i.i_exit)
		mlx_destroy_image(data->mlx, data->i.i_exit);
	if (data->i.i_move1)
		mlx_destroy_image(data->mlx, data->i.i_move1);
	if (data->i.i_move2)
		mlx_destroy_image(data->mlx, data->i.i_move2);
	if (data->i.i_move3)
		mlx_destroy_image(data->mlx, data->i.i_move3);
	if (data->i.i_move4)
		mlx_destroy_image(data->mlx, data->i.i_move4);
	if (data->i.i_score)
		mlx_destroy_image(data->mlx, data->i.i_score);
	if (data->i.i_space)
		mlx_destroy_image(data->mlx, data->i.i_space);
}

void	error(char *m, t_data *data)
{
	ft_printf("%s\n", m);
	get_next_line(-42);
	if (data->map)
		free_data_map(data);
	free_img(data);
	if (data->mlx_status == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}

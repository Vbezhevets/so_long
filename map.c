/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:36 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:11:48 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_detect(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			if (data->map[y][x] == PLAYER)
			{
				data->p_y = y;
				data->p_x = x;
			}
			if (data->map[y][x] == EXIT)
			{
				data->e_y = y;
				data->e_x = x;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_cells_ok(t_data *data, int y, int x)
{
	char	c;

	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			c = data->map[y][x];
			if (c != WALL && c != SPACE && c != SCORE
				&& c != EXIT && c != PLAYER)
				return (error(ERR_MAP, data), 1);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_map_ok(t_data *data, int y, int x)
{
	while (y < data->h - 1)
	{
		x = 0;
		while (x < data->w - 1)
		{
			if (data->map[y][x] == PLAYER)
				data->p++;
			if (data->map[y][x] == SCORE)
				data->score++;
			if (data->map[y][x] == EXIT)
				data->e++;
			if (data->map[0][x] != WALL || data->map[y][0] != WALL)
				return (error(ERR_MAP, data), 1);
			if (data->map[data->h - 1][x] != WALL)
				return (error(ERR_MAP, data), 1);
			x++;
		}
		if (data->map[y][x] != WALL)
			return (error(ERR_MAP, data), 1);
		y++;
	}
	if (data->p != 1 || data->e != 1 || data->h < 3 || data->score == 0)
		return (error(ERR_MAP, data), 1);
	return (0);
}

int	map_init(t_data *data, char *f_path)
{
	int		i;
	int		fd;
	char	*line;

	data->map = (char **)ft_calloc(data->h, sizeof (char *));
	if (data->map == NULL)
		return (error(ERR_MLC, data), 1);
	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return (error(ERR_RMP, data), 1);
	i = 0;
	while (i < data->h)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (error(ERR_RMP, data), 1);
		data->map[i] = line;
		i++;
	}
	get_next_line(-42);
	close (fd);
	return (0);
}

int	load_map(t_data *data, char *path, int prev_l, int l)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error(ERR_RMP, data), 1);
	while (l != 0)
	{
		line = get_next_line(fd);
		l = ft_strlen(line);
		if (l != prev_l && data->h > 0 && l != 0)
			return (free(line), error(ERR_MAP, data), close(fd), 1);
		if (l != 0)
		{
			prev_l = l;
			data->h++;
		}
		free(line);
	}
	close(fd);
	data->w = prev_l - 1;
	return (map_init(data, path));
}

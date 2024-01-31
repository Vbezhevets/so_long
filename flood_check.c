/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:41:45 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:49:03 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	check_exit(char **map, int y, int x)
{
	if (map[y][x + 1] != '*'
	&& map[y + 1][x] != '*'
	&& map[y - 1][x] != '*'
	&& map[y][x - 1] != '*')
		return (1);
	return (0);
}

void	flood(char **map, int y, int x, t_data *data)
{
	if (y + 1 == data->h || x + 1 == data->w || x == 0 || y == 0
		|| ft_strchr("1E*", map[y][x]))
		return ;
	map[y][x] = '*';
	flood(map, y + 1, x, data);
	flood(map, y - 1, x, data);
	flood(map, y, x + 1, data);
	flood(map, y, x - 1, data);
}

int	flood_check(t_data *data)
{
	int		i;
	char	**map;

	map = (char **)ft_calloc(data->h, sizeof(char *));
	if (!map)
		return (error(ERR_MLC, data), 1);
	i = 0;
	while (i < data->h)
	{
		map[i] = ft_strdup(data->map[i]);
		i++;
	}
	flood(map, data->p_y, data->p_x, data);
	i = 0;
	while (i < data->h)
	{
		if (ft_strchr(map[i], SCORE))
			return (f_mp(map, data->h - 1), free(map), error(ERR_MAP, data), 1);
		i++;
	}
	if (check_exit(map, data->e_y, data->e_x) != 0)
		return (f_mp(map, data->h - 1), free(map), error(ERR_MAP, data), 1);
	return (f_mp(map, data->h - 1), free(map), 0);
}

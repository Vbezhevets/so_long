/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:26 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:45:35 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	img_to_zero(t_data *data)
{
	data->i.i_wall = NULL;
	data->i.i_exit = NULL;
	data->i.i_move1 = NULL;
	data->i.i_move2 = NULL;
	data->i.i_move3 = NULL;
	data->i.i_move4 = NULL;
	data->i.i_score = NULL;
	data->i.i_space = NULL;
}

void	my_to_zero(t_data *data)
{
	data->h = 0;
	data->w = 0;
	data->p = 0;
	data->e = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->score = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->dir = 3;
	data->steps = 0;
	data->mlx_status = 0;
	data->map = NULL;
	img_to_zero(data);
}

int	is_name_right(char *argv)
{
	int	i;
	int	l;

	l = ft_strlen(argv);
	l--;
	i = 3;
	while (argv[l] == MAP_EXT[i])
	{
		l--;
		i--;
	}
	if (i > 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	my_to_zero(&data);
	if (argc != 2 || is_name_right(argv[1]) != 0)
	{
		ft_printf(ERR_RMP);
		ft_printf("\n");
		exit(1);
	}
	if (load_map(&data, argv[1], 0, 1) != 1)
	{
		if (is_map_ok(&data, 0, 0) != 0)
			exit(1);
		player_detect(&data);
		if (is_cells_ok(&data, 0, 0) != 0)
			exit(1);
		if (flood_check(&data) != 0)
			exit(1);
		mlx_go(&data);
	}
	else
		exit(1);
}

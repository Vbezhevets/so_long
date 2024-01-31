/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <bvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:25:10 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/29 19:20:40 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_images
{
	void		*i_wall;
	void		*i_score;
	void		*i_space;
	void		*i_move1;
	void		*i_move2;
	void		*i_move3;
	void		*i_move4;
	void		*i_exit;

}				t_images;

typedef struct s_data
{
	char		**map;
	int			h;
	int			w;
	int			p;
	int			e;
	int			e_x;
	int			e_y;
	int			score;
	int			p_x;
	int			p_y;
	void		*mlx;
	void		*win;
	int			dir;
	int			steps;
	int			mlx_status;
	t_images	i;

}				t_data;

# define MAP_EXT ".ber"
# define WALL '1'
# define SPACE '0'
# define SCORE 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define ERR_IMG "Error reading image"
# define ERR_MAP "Wrong map"
# define ERR_MLX "MLX error"
# define ERR_MLC "Malloc error"
# define ERR_RMP "Error reading map"

# define LEFT_A 97
# define LEFT_B 65361

# define RIGHT_A 100
# define RIGHT_B 65363

# define UP_A 119
# define UP_B 65362

# define DOWN_A 115
# define DOWN_B 65364

# define ESC 65307

# define WIND_W 400
# define WIND_H 400

# define I_S 40

int				mlx_go(t_data *data);
int				mlx_stop(t_data *data, int status);
int				key_pressed(int key, t_data *data);

void			move_up(t_data *data);
void			move_down(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);

int				flood_check(t_data *data);
int				is_cell_ok(char c);
int				is_exit_ok(t_data *data);
int				map_render(t_data *data);
int				is_action(char point, t_data *data);
int				player_detect(t_data *data);
int				is_map_ok(t_data *data, int y, int x);
int				is_cells_ok(t_data *data, int y, int x);
int				load_map(t_data *data, char *f_path, int prev_l, int l);
int				map_init(t_data *data, char *f_path);

void			*get_img(t_data *data, char c);
void			file_to_img(t_data *data, int s);

void			error(char *m, t_data *data);
void			free_img(t_data *data);
void			free_data_map(t_data *data);
void			f_mp(char **map, int h);

#endif

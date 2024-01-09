# include "functions/functlib.h"


int is_action(char point, t_data * data)
{
	if (point == SPACE)
		return (1);
	if (point == SCORE)
	{
		data->score--;
		return (1);
	}
	if (point == EXIT)
	{
		if (data->score == 0)
			mlx_stop(data);
		else
			return(0);
	}
	return (0);	
}
	
void move_up(t_data *data) 
{
	if (is_action(data->map[data->p_y - 1][data->p_x], data)) 
	{
		data->map[data->p_y - 1][data->p_x] = PLAYER;
		data->map[data->p_y][data->p_x] = SPACE;
		data->p_y--;
		data->dir = 2;
		map_render(data);
	}
}

void move_down(t_data *data)
{
	if (is_action(data->map[data->p_y + 1][data->p_x], data))
	{
		data->map[data->p_y + 1][data->p_x] = PLAYER;
		data->map[data->p_y][data->p_x] = SPACE;
		data->p_y++;
		data->dir = 4;
		map_render(data);
	}
}

void move_left(t_data *data)
{
	if (is_action(data->map[data->p_y][data->p_x - 1], data))
	{
		data->map[data->p_y][data->p_x - 1] = PLAYER;
		data->map[data->p_y][data->p_x] = SPACE;
		data->p_x--;
		data->dir = 1;
		map_render(data);
	}
}

void move_right(t_data *data)
{
	if (is_action(data->map[data->p_y][data->p_x + 1], data))
	{
		data->map[data->p_y][data->p_x + 1] = PLAYER;
		data->map[data->p_y][data->p_x] = SPACE;
		data->p_x++;
		data->dir = 3;
		map_render(data);
	}
}
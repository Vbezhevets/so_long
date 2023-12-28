# include "functions/functlib.h"

int map_anal(char point, t_data * data)
{
	if (point == '0')
		return (1);
	if (point == 'C')
	{
		data->collect--;
		return (1);
	}
	if (point == 'E')
	{
		if (data->collect == 0)
			mlx_stop(data);
		else
			return(0);
	}
	return (0);	
}

void move_up(t_data *data) 
{
	if (map_anal(data->map[data->p_y - 1][data->p_x], data)) 
	{
		data->map[data->p_y - 1][data->p_x] = 'P';
		data->map[data->p_y][data->p_x] = '0';
		data->p_y--;
		map_render(data);
	}
}

void move_down(t_data *data)
{
	if (map_anal(data->map[data->p_y + 1][data->p_x], data))
	{
		data->map[data->p_y + 1][data->p_x] = 'P';
		data->map[data->p_y][data->p_x] = '0';
		data->p_y++;
		map_render(data);
	}
}

void move_left(t_data *data)
{
	if (map_anal(data->map[data->p_y][data->p_x - 1], data))
	{
		data->map[data->p_y][data->p_x - 1] = 'P';
		data->map[data->p_y][data->p_x] = '0';
		data->p_x--;
		map_render(data);
	}
}

void move_right(t_data *data)
{
	if (map_anal(data->map[data->p_y][data->p_x + 1], data))
	{
		data->map[data->p_y][data->p_x + 1] = 'P';
		data->map[data->p_y][data->p_x] = '0';
		data->p_x++;
		map_render(data);
	}
}
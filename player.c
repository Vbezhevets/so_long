# include "functions/functlib.h"

// щодо неймінгу функції, то зазвичай, якщо функція повертає 1 або 0, то вона називається is_...
// наприклад, is_map_anal
// але тут, якщо ти використовуєш цю функцію тільки в одному місці, то можна і не змінювати
// але якщо використовуєш в багатьох місцях, то краще змінити
// так більше інтуїтивно зрозуміло, що функція повертає 1 або 0
// але це не обов'язково, це лише рекомендація
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

// мені дуже сподобалась ідея з функціями move_... все так просто і гарно працює
// дуже вдало ти розділив кожну з низ на два
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

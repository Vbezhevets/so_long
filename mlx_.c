# include "functions/functlib.h"

int key_pressed(int key, t_data *data)
{
//	printf("key: %d\n", key);
	if (key == UP_A || key == UP_B)
			move_up(data);//(move(adress))
	if (key == DOWN_A || key == DOWN_B)
		move_down(data);
	if (key == LEFT_A || key == LEFT_B)
		move_left(data);
	if (key == RIGHT_A || key == RIGHT_B)
		move_right(data);
	if (key == ESC)
		mlx_stop(data);
    return (0);
}

int mlx_go(t_data *data)
{


    data->mlx = mlx_init();
    if (data->mlx == NULL)
        return(3); //bad protection
	else
		data->win = mlx_new_window(data->mlx, (WIND_W / 10) * data->w, (WIND_H /10) * data->h, "W");
	if (data->win == NULL)
		return(free(data->mlx), 1); //bad protection
	map_render(data);
	mlx_key_hook(data->win, key_pressed, data);
	mlx_loop(data->mlx);
    return (0);
}

int mlx_stop(t_data *data)
{
    printf("GOOD BYE!!!\n");

	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
    free(data->map);
	free(data->mlx);
    exit(1);
	return(0);
}

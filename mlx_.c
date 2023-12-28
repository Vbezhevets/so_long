# include "functions/functlib.h"

int key_pressed(int key, t_data *data)
{
//	printf("key: %d\n", key);
	if (key == 119 || key == 65362)
			move_up(data);//(move(adress))
	if (key == 115 || key == 65364)
		move_down(data);
	if (key == 97 || key == 65361)
		move_left(data);
	if (key == 100 || key == 65363)
		move_right(data);
	if (key == 65307)
		mlx_stop(data);
    return (0);
}

int mlx_go(t_data *data)
{

    
    data->mlx = mlx_init();
    if (data->mlx == NULL)
        return(1); //handle
	data->win = mlx_new_window(data->mlx, 600, 400, "W");
	if (data->win == NULL)
		return(free(data->mlx), 1); //handle
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

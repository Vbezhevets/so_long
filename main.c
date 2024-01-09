
# include "functions/functlib.h"

void my_to_zero(t_data *data)
{
	data->h = 0;
	data->w = 0;
	data->p = 0;
	data->e = 0;
	data->score = 0;
	data->p_x = 0;
	data->p_y = 0;
	data->dir = 1;
}
 
int main ()
{
		t_data	data;
	ft_bzero(&data, sizeof(t_data)); // не сработало
	my_to_zero(&data);
	load_map(&data, "map/map.ber");
	if (is_map_ok(&data, 0, 0) != 0)
		return (1);
	player_detect(&data);
	mlx_go(&data);
	//printf("!");
}


# include "functions/functlib.h"

 
int main ()
{
	t_data	*data;
	
	data = (t_data*)malloc(sizeof(t_data));
	if (data == NULL)
		return (1); //need handle
 
	load_map(data, "map/map.ber");
	if (check_map(data))
	{
		scan(data);
		map_render(data);
		mlx_go(data);
	}
}
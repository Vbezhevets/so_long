/* typedef struct s_map
{
	char    **map;
	int 	h; //height
	int		w; //width
	int		score;
	int		collect;
	int		p_x;
	int		p_y;
} t_data; */
# include "functions/functlib.h"

t_data * scan(t_data *data)
{
	int x = 0;
	int y = 0;
	data->collect = 0;

	while(y < data->h)
	{
		x = 0;
		while(x < data->w)
		{
			if (data->map[y][x] == 'P') // player detection
			{
				data->p_y = y;
				data->p_x = x;
			}
			if (data->map[y][x] == 'C') // player detection
				data->collect++;
			x++;
		}
		y++;
	}
	printf("P on position %d, %d\n", data->p_y, data->p_x);
	return (data);
}

int check_map(t_data *data)
{
    if (data->h > 0) // write all checks
        return(1);
    else
        ft_printf("FUCKKK YOUR MAP!!!\n");
    return (0);
}

// функція дуже багато ліків має, будь обережний, її треба буде дуже переписати
// також нема жодного протекта на опен і гет некст лайн
int load_map(t_data *data, char *f_path)
{
	int	prev_l;
	int	l = 1;
	int fd;
	char * line;
	int i;

	fd = open(f_path, O_RDONLY);
	data->h = 0;
	while (l!=0)
	{
		line = get_next_line(fd);
		l = ft_strlen(line);
		if (l != prev_l && data->h > 0 && l != 0) // strings has various lgs
			return(1); // handle mistakes
		if (l != 0)
			prev_l = l;
		data->h++;
	}
	close(fd);
	l = prev_l;
	data->w = l;
	data->map = (char**)malloc(sizeof(char*) * (data->h));
	if (data->map == NULL)
		return(1);
	data->h--;
	data->map[data->h] = NULL;
	i = 0;
	fd = open(f_path, O_RDONLY);
	while (i < data->h)
	{
		data->map[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (data->map[i] == NULL)
			return(1);
		ft_strcpy(data->map[i], get_next_line(fd));
		i++;
	}
	close (fd);
	return (0);
}

void map_render(t_data *data)
{
	int i = 0;

	while (i < data->h)
	{
		ft_printf("%s", data->map[i]);
		i++;
	}
	ft_printf("\n");
}

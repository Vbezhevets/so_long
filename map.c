
# include "functions/functlib.h"

int is_cell_ok(char c)
{
	if (c == WALL || c == SPACE || c == SCORE)
		return (0);
	if (c == EXIT || c == PLAYER)
		return (0);
	return (1);
}
int player_detect(t_data *data)
{
	int x = 0;
	int y = 0;

	while(y < data->h - 1)
	{
		x = 0;
		while(x < data->w - 1)
		{
			if (is_cell_ok(data->map[y][x]) != 0)
				return (free_map(data, data->h), error(1), 1);
			if (data->map[y][x] == PLAYER) // player detection
			{
				data->p_y = y;
				data->p_x = x;
			}
			x++;
		}
		y++;
	//ft_printf("player position %d, %d\n", data->p_y, data->p_x);
	}
	return (0);
}

int is_map_ok(t_data *data, int y, int x)
{
	while(y < data->h)
	{
		x = 0;
		while(x < data->w - 1)
		{
			if (data->map[y][x] == PLAYER)
				data->p++;
			if (data->map[y][x] == SCORE)
				data->score++;
			if (data->map[y][x] == EXIT)
				data->e++;
			if (data->map[0][x] != WALL || data->map[y][0] != WALL)
				return (free_map(data, data->h), error(1), 1); //free_map(data, data->h)
			if (data->map[data->h - 1][x] != WALL)
				return (free_map(data, data->h), error(1), 1);
			x++;
		}
		if (data->map[y][x] != WALL)
			return (free_map(data, data->h), error(1), 1);
		y++;
	}
	if (data->p != 1 || data->e != 1 || data->h < 3 || data->score == 0)
		return (free_map(data, data->h), error(1), 1);
	return(0);
}


int map_init(t_data *data, char *f_path)
{
	int i;
	int fd;

	data->map = (char**)calloc(data->h, sizeof(char*));
	if (data->map == NULL)
		return(error(2), 1);
	data->map[data->h - 1] = NULL;
	i = 0;
	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return(error(0), 1);//bad protection, leaks
	while (i < data->h)
	{
		data->map[i] = (char *)calloc((data->w + 1), sizeof(char)); //??
		if (data->map[i] == NULL)
			return(free_map(data, i), error(2), 1); // fd memory leak
	//	line = get_next_line(fd);
		/*if (!line)
			return(free_map(data, i), error(2), 1); */
		ft_strcpy(data->map[i], get_next_line(fd));//no protection for gnl
		i++;
	}
	close (fd);
	return 0;
	}

int load_map(t_data *data, char *f_path)
{
	int	prev_l;
	int	l = 1;
	int fd;
	char * line = "1";

	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		return(error(0), 1);
	while (l != 0)
	{
		line = get_next_line(fd);//bad protection, the reason of problems below
		/*if (!line)
			return(NULL); */
		l = ft_strlen(line);
		if (l != prev_l && data->h > 0 && l != 0) // strings has various lgs
			return(error(0), close(fd), 1);  // Segmentation fault (core dumped)
		if (l != 0)
			prev_l = l;
		data->h++;
	}
	close(fd);
	data->h--;
	data->w = prev_l - 1;
	map_init(data, f_path);
	return(0);
}

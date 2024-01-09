# include "functions/functlib.h"
#include "libft/libft.h"
#include "mlx_linux/mlx.h"

char * direction(int d)
{
    char *path;

    if (d == 1)
        ft_strcpy(path, "img/move1.xpm");
    if (d == 2)
        ft_strcpy(path, "img/move2.xpm");
    if (d == 3)
        ft_strcpy(path, "img/move3.xpm");
    if (d == 4)
        ft_strcpy(path, "img/move4.xpm");
    return(path);
/*
    char c;
    char *path = "img/move";
    c = (char)d + '0';
    
    ft_strcpy(path, "img/move");
    ft_strjoin(path, &c);
    ft_strjoin(path, ".xmp");
    printf("%s", path);
   return ft_strjoin("img/move", ft_strjoin(&c, ".xmp")); */
}

t_image *get_img(t_data *data, char c)
{
    t_image *image;
    int w;
    int h;
    w = 80; //IMG_W
    h = 80; //IMG_H

    image = (t_image *)calloc(1, sizeof(t_image));
    if (!image)
    {
        error(2); 
        free_map(data, data->h);
        mlx_stop(data);
    }        
    image->path = (char *)calloc(15, sizeof(char));
    if (c == WALL)
        ft_strcpy(image->path,"img/walls.xpm");
    if (c == SCORE)
        ft_strcpy(image->path,"img/score.xpm");
    if (c == SPACE)
        ft_strcpy(image->path,"img/space.xpm");
    if (c == PLAYER)
    {
       ft_strcpy(image->path,direction(data->dir));
      //  ft_strcpy(image->path,"img/move3.xpm");
    }
    if (c == EXIT)
        ft_strcpy(image->path,"img/exit_.xpm");
    image->img = mlx_xpm_file_to_image(data->mlx, image->path, &w, &h);
        return (image);
}
void map_render(t_data *data)
{

	int y = 0;
    int x = 0;
    t_image *i_temp;

    while(y < data->h) 
	{
		x = 0;
		while(x < data->w)
		{
            i_temp = get_img(data, data->map[y][x]);
            mlx_put_image_to_window(data->mlx, data->win, i_temp->img, x * IMG_W, y * IMG_H);
			free(i_temp);
            x++;
		}
		y++;
	}
    /*
	while (i < data->h)
	{
		ft_printf("%s", data->map[i]);
          mlx_put_image_to_window(mlx, win, img, 0, 0);
		i++; 						
	}		*/
	ft_printf("\n"); 
} 

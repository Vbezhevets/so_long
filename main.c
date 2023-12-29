
# include "functions/functlib.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr[i++] = 0;
}

// 1 - never use malloc for struct, that you initialize in main, and pass within entire program
// instead, use ft_bzero, to set all bytes to 0 in stack allocated variable
// 2 - use ft_calloc instead of malloc, in case you really need to make an allocation
// exaclty the same as malloc, but it also set all bytes to 0
// It was exactly the reason, why should you include your libft here
int main ()
{
	// t_data	*data;

	// data = (t_data*)malloc(sizeof(t_data));
	// if (data == NULL)
	// 	return (1); //need handle

	t_data	data;
	ft_bzero(&data, sizeof(t_data));

	load_map(&data, "map/map.ber");
	if (check_map(&data))
	{
		scan(&data);
		map_render(&data);
		mlx_go(&data);
	}
}

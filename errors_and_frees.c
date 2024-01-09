
# include "functions/functlib.h"

void free_map(t_data * data, int q)
{
    while (q >= 0)
    {
        if (data->map[q])
            {
                free(data->map[q]);
                data->map[q] = NULL;
            }
        q--;
    }
//    free(data);  --- ее надо чистить

}
void error(int n)
{
    if (n == 0)
        ft_printf("error reading map-file\n");
    if (n == 1)
        ft_printf("wrong map\n");
    if (n == 2)
        ft_printf("alloc error\n");
    if (n == 3)
       ft_printf("mlx creation error\n");  
}
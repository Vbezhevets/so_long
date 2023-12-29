# include "functions/functlib.h"

// для чисел, які ти використовуєш в коді, краще використовувати define
// тоді, якщо ти захочеш змінити значення, то зміниш тільки в одному місці
// а не в кожному, де використовуєш, таокж це покращує читабельність коду
// також це стосується розмірів вікна, які ти використовуєш в mlx_new_window і тд
// приклад:
// # define WIN_HEIGHT 400
// # define WIN_WIDTH 600
// # define КНОПКА_ВВЕРХ 65362
// # define КНОПКА_ВНИЗ 65364
// # define КНОПКА_ВЛІВО 65361
// # define КНОПКА_ВПРАВО 65363
// і тд у твому .h файлі
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

// кожну з функцій, які ти використовуєш mlx_new_window, mlx_init,
// також це з часом буде ще mlx_new_image, то все що вони роблять, треба звільняти за допомогою mlx_destroy_...
// тобто, якщо ти використовуєш mlx_new_window, то треба звільняти за допомогою mlx_destroy_window і тд
// тому, краще зробити окрему функцію, яка буде звільняти всі ресурси, які ти використовуєш
// і викликати її в кінці програми, і взагалі всюди де потрібно звільнити ресурси
// там будь обережний з тією функцією, але вона дуже корисна
// також скачай валгрінд, і перевіряй свій код на витік пам'яті
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

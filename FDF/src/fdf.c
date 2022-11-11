
#include "fdf.h"

int	destroy_windows(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	press_button(int key, t_data *data)
{
	if (key == 53)
		destroy_windows();
	if (key == 126)
		data->move_y -= 50;
	if (key == 125)
		data->move_y += 50;
	if (key == 123)
		data->move_x -= 50;
	if (key == 124)
		data->move_x += 50;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	design(data);
	return (0);
}

int	main(int ac, char **argv)
{
	t_data	*data;

	if (ac != 2 || (open(argv[1], O_RDONLY, 0) == -1))
		return(1);
	data = parse(argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->g_image = mlx_new_image(data->mlx_ptr,1000,1000);
	data->g_data = (int *)mlx_get_data_addr(data->g_image,&data->tab[0],&data->tab[1],&data->tab[2]);

	design(data);
	int i = 0;
	system("leaks fdf");
	mlx_hook(data->win_ptr, 2, (1L << 0), press_button, data);
	mlx_hook(data->win_ptr, 17, 0L,destroy_windows, data);
	mlx_loop(data->mlx_ptr);
	free(data);
}

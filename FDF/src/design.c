

#include "fdf.h"

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham2(float x, float y, t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x += data->move_x;
	y += data->move_y;
	data->x_next += data->move_x;
	data->y_next += data->move_y;
	x_step = data->x_next - x;
	y_step = data->y_next - y;
	max = ft_max(absolute_value(x_step), absolute_value(y_step));
	 x_step /= max;
	  y_step /= max;
	while ((int)(x - data->x_next) || (int)(y - data->y_next))
	{
		 mlx_pixel_put(data->mlx_ptr, data->win_ptr, x + 200, y + 200, data->color);
		//data->g_data[(int)(1000 * (y + 200) + (x + 200) )] = data->color;
		x += x_step;
		y += y_step;
		
	}
}

void	 bresenham_law(float x, float y, int bool, t_data *data)
{
	int	z;
	int	z_next;

	if (bool)
	{
		data->x_next = x + 1;
		data->y_next = y;
	}
	else
	{
		data->x_next = x;
		data->y_next = y + 1;
	}
	z = data->mape[(int)y][(int)x];
	z_next = data->mape[(int)data->y_next][(int)data->x_next];
	x *= ZOOM;
	y *= ZOOM;
	data->x_next *= ZOOM;
	data->y_next *= ZOOM;
	isometric(&x, &y, z);
	isometric(&data->x_next, &data->y_next, z_next);
	data->color = 0xfffffff;
	if (z || z_next)
		data->color = 0xffff00;
	bresenham2(x, y, data);
}

void	design(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham_law(x, y, 1, data);
			if (y < data->height - 1)
				bresenham_law(x, y, 0, data);
			x++;
		}
		y++;
	}

	//mlx_put_image_to_window(data->mlx_ptr,data->win_ptr,data->g_image,0,0);
	//mlx_destroy_image(data->mlx_ptr,data->g_image);
}

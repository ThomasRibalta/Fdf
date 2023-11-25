#include "../fdf.h"

void	config_cord(float x, float y, int n, t_data *data)
{
	if (!n)
	{
		data->x = x;
		data->x1 = x + 1;
		data->y = y;
		data->y1 = y;
	}
	else
	{
		data->x = x;
		data->x1 = x;
		data->y = y;
		data->y1 = y + 1;
	}
}

int	relief(t_data *data, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		while (j < data->width)
		{
			if (data->matrice[i][j] > 0 && data->min + n != 0)
				data->matrice[i][j] += n;
			else if (data->matrice[i][j] < 0 && data->min2 + n != 0)
				data->matrice[i][j] += n;
			j++;
		}
		j = 0;
		i++;
	}
	if (data->min + n != 0)
		data->min += n;
	if (data->min2 + n != 0)
		data->min2 += n;
	return (0);
}

void	aff(t_data *data, float interx, float intery)
{
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		if (data->x + data->xmove < 1200 && data->y + data->ymove < 600
			&& data->x + data->xmove > -1 && data->y + data->ymove > -1)
			data->img_data[((int)data->y + data->ymove) * 1200 + ((int)data->x
					+ data->xmove)] = data->color;
		data->x += interx;
		data->y += intery;
	}
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->matrice[i]);
		i++;
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->matrice);
	free(data);
	exit(0);
}

void	get_min(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->min = 2147483647;
	data->min2 = -2147483648;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
		{
			if (data->min > data->matrice[i][j] && data->matrice[i][j] > 0)
				data->min = data->matrice[i][j];
			if (data->min2 < data->matrice[i][j] && data->matrice[i][j] < 0)
				data->min2 = data->matrice[i][j];
		}
	}
}

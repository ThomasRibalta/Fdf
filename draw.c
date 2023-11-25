/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:00:51 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/12 14:17:59 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absol(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	get_color(t_data *data)
{
	data->color = 16777215;
	if (data->matrice[(int)data->y][(int)data->x])
		data->color = 16711935 + 10 * (data->matrice[(int)data->y][(int)data->x]
				* 7);
	data->x *= data->zoom;
	data->y *= data->zoom;
}

void	bresenham(t_data *data)
{
	float	maxi;
	float	interx;
	float	intery;
	int		z;
	int		z1;

	z = data->matrice[(int)data->y][(int)data->x];
	z1 = data->matrice[(int)data->y1][(int)data->x1];
	get_color(data);
	zoom(data);
	if (data->parallel < 0)
	{
		rotate_axe(&data->x, &data->y, &z, data);
		rotate_axe(&data->x1, &data->y1, &z1, data);
		iso(0, z, data);
		iso(1, z1, data);
	}
	interx = data->x1 - data->x;
	intery = data->y1 - data->y;
	maxi = max(absol(interx), absol(intery));
	interx /= maxi;
	intery /= maxi;
	aff(data, interx, intery);
}

int	draw(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	clear_img(data);
	while (++i < data->height)
	{
		while (++j < data->width)
		{
			if (j < data->width - 1)
			{
				config_cord(j, i, 0, data);
				bresenham(data);
			}
			if (i < data->height - 1)
			{
				config_cord(j, i, 1, data);
				bresenham(data);
			}
		}
		j = -1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

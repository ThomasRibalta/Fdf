/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:14:22 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/09 10:19:33 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	erreur_mess(char *str)
{
	ft_putstr_fd("\e[31m", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(0);
}

void	clear_img(t_data *data)
{
	int	i;
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	i = 0;
	data->img_data = (int *)mlx_get_data_addr(data->img_ptr, &bits_per_pixel,
			&size_line, &endian);
	while (i < 1200 * 600)
		data->img_data[i++] = 0;
}

void	iso(int n, int z, t_data *data)
{
	if (!n)
	{
		data->x = (data->x - data->y) * cos(0.5);
		data->y = (data->x + data->y) * sin(0.5) - z;
	}
	else
	{
		data->x1 = (data->x1 - data->y1) * cos(0.5);
		data->y1 = (data->x1 + data->y1) * sin(0.5) - z;
	}
}

void	zoom(t_data *data)
{
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
}

void	rotate(int key, t_data *data)
{
	if (key == 105)
		data->rx -= 0.1;
	if (key == 107)
		data->rx += 0.1;
	if (key == 108)
		data->ry -= 0.1;
	if (key == 111)
		data->ry += 0.1;
	if (key == 109)
		data->rz -= 0.1;
	if (key == 117)
		data->rz += 0.1;
}

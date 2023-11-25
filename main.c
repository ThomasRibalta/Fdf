/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:04:10 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/12 14:21:12 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key, t_data *data)
{
	if (key == 97)
		data->zoom += 1;
	if (key == 101)
		data->zoom -= 1;
	if (key == 122)
		data->ymove -= 3;
	if (key == 113)
		data->xmove -= 3;
	if (key == 115)
		data->ymove += 3;
	if (key == 100)
		data->xmove += 3;
	if (key == 112)
		data->parallel *= -1;
	if (key == 105 || key == 107 || key == 108 || key == 111 || key == 109
		|| key == 117)
		rotate(key, data);
	if (key == 65362)
		relief(data, 1);
	if (key == 65364)
		relief(data, -1);
	if (key == 65307)
		free_all(data);
	return (0);
}

void	rotate_axe(float *x, float *y, int *z, t_data *data)
{
	float	tmp_y;
	float	tmp_x;

	tmp_y = *y;
	*y = tmp_y * cos(data->rx) + *z * sin(data->rx);
	*z = -tmp_y * sin(data->rx) + *z * cos(data->rx);
	tmp_x = *x;
	*x = tmp_x * cos(data->ry) + *z * sin(data->ry);
	*z = -tmp_x * sin(data->ry) + *z * cos(data->ry);
	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(data->rz) - tmp_y * sin(data->rz);
	*y = tmp_x * sin(data->rz) + tmp_y * cos(data->rz);
}

void	init_data(t_data *data)
{
	data->zoom = 15;
	data->ymove = 300;
	data->xmove = 600;
	data->x = 0;
	data->x1 = 0;
	data->y = 0;
	data->y1 = 0;
	data->rx = 0;
	data->ry = 0;
	data->rz = 0;
	data->parallel = -1;
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1200, 600);
}

void	start(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1200, 600, "42FDF");
	init_data(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, close_win, data);
	mlx_loop_hook(data->mlx_ptr, draw, data);
	mlx_loop(data->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		erreur_mess("Invalid argument");
	check_file(av[1]);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(0);
	parsing(av[1], data);
	start(data);
}

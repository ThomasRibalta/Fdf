/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:11:25 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/12 14:18:34 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "utils/get_next_line/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		**matrice;
	int		zoom;
	int		xmove;
	int		color;
	int		ymove;
	int		min;
	int		min2;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	rx;
	float	ry;
	float	rz;
	int		parallel;
	void	*img_ptr;
	int		*img_data;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

void		rotate_axe(float *x, float *y, int *z, t_data *data);
void		config_cord(float x, float y, int n, t_data *data);
void		aff(t_data *data, float interx, float intery);
void		check_file(char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			close_win(t_data *data);
void		free_all(t_data *data);
void		get_min(t_data *data);
void		erreur_mess(char *str);
int			relief(t_data *data, int n);
void		clear_img(t_data *data);
void		zoom(t_data *data);
void		rotate(int key, t_data *data);
void		iso(int n, int z, t_data *data);
void		parsing(char *str, t_data *data);
void		ft_putstr_fd(char *s, int fd);
int			draw(t_data *data);
int			ft_atoi(const char *str);
char		**ft_split(char *s, char c);
char		*get_next_line(int fd, int n);
int			count_words(char *str, char c);

#endif

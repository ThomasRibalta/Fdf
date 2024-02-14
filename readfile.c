/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:21:16 by thoribal          #+#    #+#             */
/*   Updated: 2023/11/09 11:22:49 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	get_width(char *str)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd, 1);
	i = count_words(line, ' ');
	free(line);
	close(fd);
	return (i);
}

int	get_height(char *str)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd, 1);
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	free(line);
	return (i);
}

void	get_matrice(char *str, t_data *data)
{
	int		fd;
	int		i;
	int		j;
	char	**split;
	char	*line;

	i = -1;
	j = -1;
	fd = open(str, O_RDONLY);
	while (++i != data->height)
	{
		line = get_next_line(fd, 1);
		split = ft_split(line, ' ');
		free(line);
		while (++j != data->width)
		{
			data->matrice[i][j] = ft_atoi(split[j]);
			free(split[j]);
		}
		free(split);
		j = -1;
	}
	get_next_line(fd, 0);
	close(fd);
}

void	parsing(char *str, t_data *data)
{
	int	i;

	i = 0;
	data->width = get_width(str);
	data->height = get_height(str);
	data->matrice = malloc(sizeof(int *) * (data->height + 1));
	while (i != data->height)
		data->matrice[i++] = malloc(sizeof(int) * (data->width + 1));
	get_matrice(str, data);
	get_min(data);
}

void	check_file(char *str)
{
	char	*dot;
	int		fd;
	int		len;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		erreur_mess("Erreur ouverture fichier !");
	len = ft_strlen(str);
	dot = ft_substr(str, len - 4, len);
	if (ft_strcmp(dot, ".fdf") != 0)
	{
		free(dot);
		erreur_mess("Mauvais type de fichier !");
	}
	free(dot);
}

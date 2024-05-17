/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:21:16 by thoribal          #+#    #+#             */
/*   Updated: 2024/05/18 00:15:47 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void parse_file(char *str, t_data *data)
{
    int fd = open(str, O_RDONLY);
    int i;
    char *line;

    i = 0;
    line = get_next_line(fd);
    data->width = count_words(line, ' ');
    data->matrice = malloc(sizeof(int *) * 1000);
    while (line)
    {
        data->matrice[i] = malloc(sizeof(int) * data->width);
        char **split = ft_split(line, ' ');
        int j = 0;
        while (split[j])
        {
            data->matrice[i][j] = atoi(split[j]);
			free(split[j]);
            j++;
        }
		free(split);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    data->matrice[i] = NULL;
    data->height = i;
    get_min(data);
}


void parsing(char *str, t_data *data)
{
	parse_file(str, data);
	get_min(data);
}

void check_file(char *str)
{
	char *dot;
	int fd;
	int len;

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

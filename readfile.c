/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:21:16 by thoribal          #+#    #+#             */
/*   Updated: 2024/05/17 17:25:13 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void parse_file(char *str, t_data *data) {
    int fd, i, j, word_count;
    char *line;
    char **split;
    int **temp_matrix;
    int rows_allocated = 0;
    int cols = 0;

    fd = open(str, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    temp_matrix = NULL;
    i = 0;
    while ((line = get_next_line(fd)) != NULL) {
        if (temp_matrix == NULL) {
            word_count = count_words(line, ' ');
            cols = word_count;
            temp_matrix = malloc(sizeof(int *) * (i + 1));
        } else if (i >= rows_allocated) {
            rows_allocated += 50;
            temp_matrix = realloc(temp_matrix, sizeof(int *) * rows_allocated);
        }
        split = ft_split(line, ' ');
        temp_matrix[i] = malloc(sizeof(int) * cols);
        j = 0;
        while (split[j]) {
            temp_matrix[i][j] = ft_atoi(split[j]);
            free(split[j]);
            j++;
        }
        free(split);
        free(line);
        i++;
    }
    close(fd);
    data->height = i;
    data->width = cols;
    data->matrice = malloc(sizeof(int *) * data->height);
    for (int k = 0; k < data->height; k++) {
        data->matrice[k] = temp_matrix[k];
    }
    free(temp_matrix);
    get_min(data);
}

void	parsing(char *str, t_data *data)
{
	parse_file(str, data);
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

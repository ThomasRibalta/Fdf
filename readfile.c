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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (dest);
	while (n > i)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

void* ft_realloc(void* ptr, size_t original_size, size_t new_size)
{
    void* ptr_new;
    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }
    else if (!ptr)
    {
        return (malloc(new_size));
    }
    else if (new_size <= original_size)
    {
        return (ptr);
    }
    else
    {
        ptr_new = malloc(new_size);
        if (ptr_new)
        {
            ft_memcpy(ptr_new, ptr, original_size);
            free(ptr);
        }
        return (ptr_new);
    }
}

void allocate_temp_matrix(int i, int **temp_matrix, int *rows_allocated)
{
    if (*temp_matrix == NULL)
    {
        *temp_matrix = malloc(sizeof(int *) * (i + 1));
    }
    else if (i >= *rows_allocated)
    {
        *rows_allocated += 50;
        *temp_matrix = realloc(*temp_matrix, sizeof(int *) * (*rows_allocated));
    }
}

void fill_temp_matrix(int i, int **temp_matrix, char *line, int cols)
{
    char **split = ft_split(line, ' ');
    temp_matrix[i] = malloc(sizeof(int) * cols);
    int j = 0;
    while (split[j])
    {
        temp_matrix[i][j] = ft_atoi(split[j]);
        free(split[j]);
        j++;
    }
    free(split);
}

void copy_temp_to_data(t_data *data, int **temp_matrix)
{
    data->matrice = malloc(sizeof(int *) * data->height);
    for (int k = 0; k < data->height; k++)
    {
        data->matrice[k] = (*temp_matrix)[k];
    }
}

void parse_file(char *str, t_data *data)
{
    int fd, i, j, word_count;
    char *line;
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
        }
        allocate_temp_matrix(i, &temp_matrix, &rows_allocated);
        fill_temp_matrix(i, &temp_matrix, line, cols);
        i++;
    }
    data->height = i;
    data->width = cols;
    copy_temp_to_data(data, &temp_matrix);
    close(fd);
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

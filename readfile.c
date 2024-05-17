/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:21:16 by thoribal          #+#    #+#             */
/*   Updated: 2024/05/17 18:56:32 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void parsing(char *str, t_data *data)
{
	parse_file(data, open(str, O_RDONLY));
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

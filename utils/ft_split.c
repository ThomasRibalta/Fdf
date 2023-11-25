/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoribal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:07:18 by thoribal          #+#    #+#             */
/*   Updated: 2023/10/05 12:56:06 by thoribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_words(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

int	ft_strlenc(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char	*get_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (ft_strlenc(str, c) + 1));
	while (i < ft_strlenc(str, c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0')
		{
			tab[i] = get_word(s, c);
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[i] = 0;
	return (tab);
}

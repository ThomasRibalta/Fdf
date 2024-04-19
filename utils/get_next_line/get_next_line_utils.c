/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:36:09 by jedurand          #+#    #+#             */
/*   Updated: 2024/01/12 15:50:49 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Looks for a newline character in the given linked list. */

int	found_newline(t_glist *stash)
{
	int		i;
	t_glist	*last;

	if (stash == NULL)
		return (0);
	last = ft_lst_get_last(stash);
	i = 0;
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* Returns a pointer to the last node in our stash */

t_glist	*ft_lst_get_last(t_glist *stash)
{
	t_glist	*current;

	current = stash;
	if (current == NULL)
		return (current);
	while (current->next)
		current = current->next;
	return (current);
}

/* Calculates the number of chars in the current line, including the trailing
 * \n if there is one, and allocates memory accordingly. */

void	generate_line(char **line, t_glist *stash)
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i] && stash->content[i] != '\n')
		{
			len++;
			i++;
		}
		if (stash->content[i] == '\n')
			len++;
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

/* Frees the entire stash. */

void	free_stash(t_glist *stash)
{
	t_glist	*current;
	t_glist	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

// int	ft_strlen(const char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (*(str++))
// 		len++;
// 	return (len);
// }

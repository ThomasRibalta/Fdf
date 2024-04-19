/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:36:50 by jedurand          #+#    #+#             */
/*   Updated: 2024/01/12 16:13:11 by jedurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_glist
{
	char			*content;
	struct s_glist	*next;
}				t_glist;

char	*get_next_line(int fd);
int		found_newline(t_glist *stash);
t_glist	*ft_lst_get_last(t_glist *stash);
void	read_and_stash(int fd, t_glist **stash);
void	extract_line(t_glist *stash, char **line);
void	generate_line(char **line, t_glist *stash);
void	clean_stash(t_glist **stash);
void	free_stash(t_glist *stash);
#endif

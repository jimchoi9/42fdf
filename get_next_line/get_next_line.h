/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimchoi <jimchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:37:33 by jimchoi           #+#    #+#             */
/*   Updated: 2024/03/13 18:28:16 by jimchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	int				size;
	char			save[BUFFER_SIZE + 1];
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*get_strchr(const char *s, int c);
t_list	*find_node(t_list **head, int fd);
char	*clear(t_list **lst, t_list *node, int fd, char *line);
int		read_line(t_list *node, int fd);
int		get_strlen(char *s);
char	*make_line(t_list *node, char *line, int size);
int		find_line(t_list *node);
void	*get_bzero(void *s, size_t n);
void	make_save(t_list *node, int size);

#endif
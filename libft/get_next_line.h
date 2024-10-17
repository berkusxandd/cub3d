/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkaragoz <tkaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:10:40 by tkaragoz          #+#    #+#             */
/*   Updated: 2024/10/07 17:10:42 by tkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define FD_MAX 500
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*move_buf_nl(char *buffer, char **next_line);

void	*gnl_calloc(size_t n, size_t size);

size_t	gnl_strlen(char *str);

char	*gnl_strjoin(char *old, char *tmp);

char	*gnl_substr(char *s, unsigned int start, size_t len);

void	remove_begin(char *buffer);

int		get_nl(char *buf);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abalhamm <abalhamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:10:45 by abalhamm          #+#    #+#             */
/*   Updated: 2023/02/19 22:16:56 by abalhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_read_to_buffer(int fd, char *buffer);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *buffer, char *buff);
size_t	ft_strlen(char *s);
char	*ft_line_get(char *buffer);
char	*ft_new_line(char *buffer);

#endif
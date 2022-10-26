/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:49:01 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/26 11:43:37 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_gnl_read(int fd, char *buffer);
char	*ft_gnl_get_line(char *buffer);
char	*ft_gnl_remove_old_line(char *buffer);
void	*ft_calloc(size_t nb_elem, size_t size_elem);
int		ft_gnl_strchr(char *str);
char	*ft_gnl_strjoin(char *line, char *buff);
size_t	ft_strlen(char *str);
char	*ft_strndup(char *str, size_t end);

#endif
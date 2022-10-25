/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:50:59 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/25 18:10:12 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_gnl_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_gnl_get_line(buffer);
	buffer = ft_gnl_remove_old_line(buffer);
	return (line);
}

char	*ft_gnl_read(int fd, char *res)
{
	ssize_t	bytes_readed;
	char	*buffer;

	if (!res)
		res = (char *)ft_calloc(1, 1);
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!res || !buffer)
		return (NULL);
}

char	*ft_gnl_get_line(char *buffer)
{

}

char	*ft_gnl_remove_old_line(char *buffer)
{

}

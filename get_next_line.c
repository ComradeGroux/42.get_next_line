/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:10:34 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/25 15:29:04 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest_str = ft_gnl_read(fd, rest_str);
	if (!rest_str)
		return (NULL);
	line = ft_gnl_get_line(rest_str);
	rest_str = ft_gnl_new_str(rest_str);
	return (line);
}

char	*ft_gnl_read(int fd, char *str)
{
	char	*buff;
	ssize_t	bytes_readed;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_readed = 1;
	while (bytes_readed != 0 && !(ft_gnl_strchr(str, '\n')))
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_readed] = '\0';
		str = ft_gnl_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_gnl_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

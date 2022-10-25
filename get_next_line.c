/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:10:34 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/25 14:10:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_gnl_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_gnl_get_line(str);
	return (line);
}

char	*ft_gnl_read(int fd, char *str)
{
	char	*buff;
	int		bytes_readed;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes_readed = 1;
	while (bytes_readed != 0 || !(ft_strchr(str, '\n')))
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_readed] = '\0';
		str = ft_strjoin(str, buff);
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

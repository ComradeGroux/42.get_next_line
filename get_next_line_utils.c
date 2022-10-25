/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:11:18 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/25 14:15:35 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr_temp;

	i = 0;
	ptr_temp = (char *)s;
	while (ptr_temp[i] != (char)c)
	{
		if (ptr_temp[i] == '\0')
			return (NULL);
		i++;
	}
	return (&ptr_temp[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_malloc;

	len_malloc = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	str = (char *)malloc(len_malloc * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}

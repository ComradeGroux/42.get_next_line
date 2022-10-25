/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:51:12 by vgroux            #+#    #+#             */
/*   Updated: 2022/10/25 18:05:52 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nb_elem * size_elem);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i <= (nb_elem * size_elem))
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:08 by mbucci            #+#    #+#             */
/*   Updated: 2022/05/18 11:31:01 by mbucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*free_map(t_map *ptr)
{
	if (ptr)
	{
		if (ptr->map)
			ptr->map = ft_free_tab((void **)ptr->map);
		if (ptr->no_path)
			free(ptr->no_path);
		if (ptr->so_path)
			free(ptr->so_path);
		if (ptr->we_path)
			free(ptr->we_path);
		if (ptr->ea_path)
			free(ptr->ea_path);
		free(ptr);
	}
	return (NULL);
}

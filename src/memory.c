/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:08:05 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 22:08:07 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft.h"

char	*ft_smart_free(char **str)
{
	free(str);
	return (NULL);
}

int	ft_free_mat_partial(t_map *map, int rows)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		free(map->mat[row]);
		row++;
	}
	free(map->mat);
	return (FALSE);
}

void	ft_free_mat(t_map *map)
{
	ft_free_mat_partial(map, map->rows);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:07:15 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 22:07:18 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

#include "ft.h"

char	*ft_read_map_data_row(int fd)
{
	char	**strs;
	char	*row_str;
	char	buffer[2];

	strs = (char **) malloc(sizeof(char *) * 2);
	if (!strs)
		return (NULL);
	strs[0] = (char *) malloc(sizeof(char));
	if (!(strs[0]))
		return (ft_smart_free(strs));
	strs[0][0] = '\0';
	row_str = strs[0];
	strs[1] = buffer;
	buffer[1] = '\0';
	while ((read(fd, buffer, 1)) && buffer[0] != '\0' && buffer[0] != '\n')
	{
		row_str = ft_strjoin(2, strs, "");
		free(strs[0]);
		if (!row_str)
			break ;
		strs[0] = row_str;
	}
	free(strs);
	return (row_str);
}

int	ft_read_map_data(int fd, t_map *map)
{
	int		row;
	char	*row_str;

	map->mat = (char **) malloc(sizeof(char *) * map->rows);
	if (!(map->mat))
		return (FALSE);
	row = 0;
	while (row < map->rows)
	{
		row_str = ft_read_map_data_row(fd);
		if (!row_str || (map->cols != 0 && ft_strlen(row_str) != map->cols)
			|| !ft_is_map_row_valid(row_str, map) || ft_strlen(row_str) == 0)
		{
			if (row_str)
				free(row_str);
			return (ft_free_mat_partial(map, row));
		}
		map->cols = ft_strlen(row_str);
		(map->mat)[row] = row_str;
		row++;
	}
	if (row != map->rows || read(fd, row_str, 1))
		return (ft_free_mat_partial(map, row));
	return (TRUE);
}

int	ft_init_map_meta(t_map *map, char *meta)
{
	int	idx;

	idx = 0;
	while (meta[idx] != '\0')
	{
		if (!ft_is_printable(meta[idx])
			|| ft_occurrences(meta[idx], meta) > 1)
		{
			return (FALSE);
		}
		idx++;
	}
	map->empt = meta[0];
	map->obst = meta[1];
	map->full = meta[2];
	return (TRUE);
}

int	ft_read_map_meta(int fd, t_map *map)
{
	char	buffer;
	char	meta[4];
	int		idx;

	while (read(fd, &buffer, 1) && ft_is_number(buffer))
	{
		map->rows = map->rows * 10 + buffer - '0';
	}
	if (map->rows == 0)
		return (FALSE);
	idx = 0;
	while (idx < 3)
	{
		meta[idx] = buffer;
		if (!read(fd, &buffer, 1))
			return (FALSE);
		idx++;
	}
	if (buffer != '\n')
		return (FALSE);
	meta[3] = '\0';
	if (!ft_init_map_meta(map, meta))
		return (FALSE);
	return (TRUE);
}

int	ft_read_map(int fd, t_map *map)
{
	if (!ft_read_map_meta(fd, map)
		|| !ft_read_map_data(fd, map))
	{
		return (FALSE);
	}
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:07:34 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 22:07:37 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"

t_square	get_square(int row, int col, t_map *map, t_square sqr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (row == map->rows || col == map->cols)
		return (sqr);
	while (i < sqr.size + 1)
	{
		if (map->mat[sqr.x + i][col] == map->obst)
			return (sqr);
		i++;
	}
	while (j < sqr.size + 1)
	{
		if (map->mat[row][sqr.y + j] == map->obst)
			return (sqr);
		j++;
	}
	if (map->mat[row][col] == map->obst)
		return (sqr);
	sqr.size++;
	sqr = get_square(row + 1, col + 1, map, sqr);
	return (sqr);
}

void	ft_get_max_row(int row, t_map *map, t_square *max_sqr, t_square *sqr)
{
	int	col;

	col = 0;
	while (col < map->cols)
	{
		sqr->x = row;
		sqr->y = col;
		sqr->size = 0;
		*sqr = get_square(row, col, map, *sqr);
		if (sqr->size > max_sqr->size)
		{
			max_sqr->size = sqr->size;
			max_sqr->x = sqr->x;
			max_sqr->y = sqr->y;
		}
		col++;
	}
}

int	ft_get_max_square(t_map *map, t_square *max_sqr)
{
	int			row;
	t_square	sqr;

	max_sqr->x = -1;
	max_sqr->y = -1;
	max_sqr->size = 0;
	row = 0;
	while (row < map->rows)
	{
		ft_get_max_row(row, map, max_sqr, &sqr);
		row++;
	}
	if (max_sqr->size == 0)
		return (FALSE);
	return (TRUE);
}

void	ft_update_map(t_map *map, t_square *sqrt)
{
	int	i;
	int	j;

	i = 0;
	while (i < sqrt->size)
	{
		j = 0;
		while (j < sqrt->size)
		{
			map->mat[sqrt->x + i][sqrt->y + j] = map->full;
			j++;
		}
		i++;
	}
}

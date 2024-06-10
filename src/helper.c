/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:53:14 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 12:53:24 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_is_map_element_valid(char c, t_map *map)
{
	if (c != map->empt && c != map->obst)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	ft_is_map_row_valid(char *row, t_map *map)
{
	int	idx;

	idx = 0;
	while (row[idx] != '\0')
	{
		if (! ft_is_map_element_valid(row[idx], map))
		{
			return (FALSE);
		}
		idx++;
	}
	return (TRUE);
}

int	ft_is_printable(char c)
{
	if (32 <= c && c <= 126)
	{
		return (TRUE);
	}
	return (FALSE);
}

int	ft_is_number(char c)
{
	if ('0' <= c && c <= '9')
	{
		return (TRUE);
	}
	return (FALSE);
}

int	ft_occurrences(char c, char *str)
{
	int	n;
	int	idx;

	n = 0;
	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == c)
		{
			n++;
		}
		idx++;
	}
	return (n);
}

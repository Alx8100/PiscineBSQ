/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 22:07:47 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 22:07:50 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft.h"

void	ft_print_error(void)
{
	write(STDERR_FILENO, "map error\n", 10);
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(STDOUT_FILENO, (map->mat)[i], ft_strlen((map->mat)[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

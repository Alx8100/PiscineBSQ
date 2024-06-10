/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:59:16 by abonanno          #+#    #+#             */
/*   Updated: 2024/06/06 21:59:19 by abonanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "ft.h"

int	ft_max_square(int fd)
{
	t_map		map;
	t_square	sqr;

	ft_init_map(&map);
	if (!ft_read_map(fd, &map))
	{
		return (FALSE);
	}
	if (!ft_get_max_square(&map, &sqr))
	{
		ft_free_mat(&map);
		return (FALSE);
	}
	ft_update_map(&map, &sqr);
	ft_print_map(&map);
	ft_free_mat(&map);
	return (TRUE);
}

int	ft_max_square_file(char *path)
{
	int	fd;
	int	ret;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (FALSE);
	}
	ret = ft_max_square(fd);
	close(fd);
	return (ret);
}

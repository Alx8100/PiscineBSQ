/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:58:02 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 12:51:56 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	main(int argc, char **argv)
{
	int	idx;

	if (argc < 2)
	{
		if (!ft_max_square(STDIN_FILENO))
			ft_print_error();
	}
	else
	{
		idx = 1;
		while (idx < argc)
		{
			if (!ft_max_square_file(argv[idx]))
				ft_print_error();
			if (idx != argc - 1)
				write(STDOUT_FILENO, "\n", 1);
			idx++;
		}
	}
	return (0);
}

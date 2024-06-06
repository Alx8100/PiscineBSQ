/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nipollin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 08:58:02 by nipollin          #+#    #+#             */
/*   Updated: 2024/06/06 12:25:45 by nipollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define	TRUE	1
#define	FALSE	0

#define	OK	0
#define	KO	-1

#define	BUFFER_SIZE	1024

t_square	*ft_find_max_square(t_map *map);
void		ft_update_map(map, sqr);
void		ft_print_map(map, sqr);
void		ft_free_map(map);
void		ft_free_square(sqr);
void		ft_print_error(); // TODO

ft_read_map_data(int fd, )
{

}

int	ft_is_meta_valid(unsigned char *meta)
{
	int	idx;

	if (!ft_is_number(meta[META_ROWS]))
	{
		return (FALSE);
	}
	idx = 1
	while (idx < META_LENGTH - 1)
	{
		if (!ft_is_printable(meta[idx])
			|| ft_occurrences(meta[idx], meta + 1) > 1)
		{
			return (FALSE);
		}
		idx++;
	}
	if (meta[META_LENGTH - 1] != '\n')
	{
		return (FALSE);
	}
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
	int	idx;

	idx = 0;
	while (str[])
}

void	ft_init_map(t_map map, char *meta)
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
}

int	ft_read_map_meta(int fd, t_map *map)
{
	unsigned char	c;
	unsigned char	meta[4];
	int				idx;
	int				rows;
	int				size;
	
	c = '0';
	while (ft_is_number(c))
	{
		if (!read(fd, &c, 1))
			return (FALSE);
		map->rows = map->rows * 10 + c - '0';
	}
	if (map->rows == 0)
	{
		return (FALSE);
	}
	idx = 0;
	while (idx < 3)
	{
		meta[idx] = c;
		if (!read(fd, &c, 1))
			return (FALSE);
		idx++;
	}
	if (c != '\n')
		return (FALSE);
	meta[4] = '\0';
	ft_init_map(map, meta);
	return (TRUE);
}

int	ft_read_map(int fd, *t_map)
{
	if (!ft_read_map_meta(fd, map) ||
		!ft_read_map_data(fd, map))
	{
		return (FALSE);
	}
	return (TRUE);
}

int		ft_max_square(int	fd);
{
	t_map		map;
	t_square	sqr;

	ft_init_map(&map);
	ret = ft_read_map(fd, &map);
	if (map == NULL)
	{
		return (FALSE);
	}
	sqr = ft_find_max_square(map);
	if (square == NULL)
	{
		ft_free_map(map);
		return (FALSE);
	}
	ft_update_map(map, sqr);
	ft_print_map(map, sqr);
	ft_free_map(map);
	//ft_free_square(sqr);
	return (TRUE);
}

/*{
	map.rows=100;
	map.cols=100;
	map.mat = (unsigned char**)malloc(sizeof(unsigned char*) * map.rows);
    for (i = 0; i < map.rows; i++) 
	{
        map.mat[i] = (unsigned char*)malloc(sizeof(unsigned char) * map.cols);
    }
	map=readfile(file,map);
	stampamatrice(map);
	t_square sqrt=get_max_square(map);
	//write(1,"\n",1);
	map.mat=changematrix(map,sqrt);
	stampamatrice(map);
	printf("\n%i\n",sqrt.x);
	printf("%i\n",sqrt.y);
	printf("%i\n",sqrt.size);
}*/

int		ft_max_square_file(char *path)
{
	int	fd;
	int	ret;

	fd = open(path, O_RDONLY);
	if (fd == KO)
	{
		return (FALSE);
	}
	ret = find_max_square(fd);
	close(fd);
	return (ret);
}

int main(int argc, char **argv)
{
	int	idx;

	if (argc < 2)
	{
		if (!ft_max_square(STDIN_FILENO))
		{
			ft_print_error();
		}
	}
	else
	{
		idx = 1;
		while (idx < argc)
		{
			if (!ft_max_square_file(argv[idx]))
			{
				ft_print_error();
			}
			idx++;
		}
	}
	return (OK);
}

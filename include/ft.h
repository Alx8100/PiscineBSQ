/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonanno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:50:39 by abonanno          #+#    #+#             */
/*   Updated: 2024/06/06 21:50:41 by abonanno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define TRUE	1
# define FALSE	0

typedef struct s_map
{
	int		rows;
	int		cols;
	char	**mat;
	char	empt;
	char	obst;
	char	full;
}	t_map;

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

int				ft_strlen(char *str);
int				ft_strstrlen(int size, char **strstr);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strjoin(int size, char **strs, char *sep);
int				ft_is_map_element_valid(char c, t_map *map);
int				ft_is_map_row_valid(char *row_str, t_map *map);
int				ft_is_printable(char c);
int				ft_is_number(char c);
int				ft_occurrences(char c, char *str);
void			ft_init_map(t_map *map);
char			*ft_read_map_data_row(int fd);
int				ft_read_map_data(int fd, t_map *map);
int				ft_init_map_meta(t_map *map, char *meta);
int				ft_read_map_meta(int fd, t_map *map);
int				ft_read_map(int fd, t_map *map);
int				ft_max_square(int fd);
int				ft_max_square_file(char *path);
char			*ft_smart_free(char **str);
int				ft_free_mat_partial(t_map *map, int rows);
void			ft_free_mat(t_map *map);
void			ft_print_error(void);
void			ft_print_map(t_map *map);
t_square		get_square(int row, int col, t_map *map, t_square sqr);
int				ft_get_max_square(t_map *map, t_square *max_sqr);
void			ft_update_map(t_map *map, t_square *sqrt);
#endif

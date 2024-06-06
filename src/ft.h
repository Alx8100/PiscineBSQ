#ifndef FT_H
# define FT_H
typedef struct s_map
{
	int rows;
	int cols;
	unsigned char **mat;
	unsigned char empt;
	unsigned char obst;
	unsigned char full;
} t_map;
typedef struct s_square
{
	int x;
	int y;
	int size;
} t_square;
#endif

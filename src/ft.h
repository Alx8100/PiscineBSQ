#ifndef FT_H
# define FT_H
typedef struct s_info_map
{
	int size;
	unsigned char empty;
	unsigned char obstacle;
	unsigned char full;
} t_info_map;
typedef struct s_square
{
	int x;
	int y;
	int size;
} t_square;
#endif FT_H

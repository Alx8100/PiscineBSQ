#include "ft.h"
t_square getMaxSquare(unsigned char **mat, int posX, int posY, t_map *map)
{
	int	row;
	int	col;
	t_square	max_sqr;
	t_square	sqr;
	
	max_sqr.row = -1;
	max_sqr.col = -1;
	max_sqr.size = 0;
	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.cols)
		{
			sqr = get_square(row, col, map);
			if (sqr.size > max_sqr.size)
			{
				//ft_cpy_sqr(&max_sqr, &sqr);
				max_sqr = sqr;
			}
			col++;
		}
		row++;
	}
}

t_square getSquare(unsigned char **mat, int row, int col, t_info_map *s)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while(i<s.size)
    {
        j = 0;
        while(j<s.size)
        {
            
        }
    }
}
int main(int argc, char ** argv)
{
}

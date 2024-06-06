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
			sqr.x = rows;
			sqr.y = cols;
			sqr = get_square(row, col, map, sqr);
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

t_square getSquare(int row, int col, t_map *map, t_square sqr)
{
    while(i<s.size)
    {
        j = 0;
        while(j<s.size)
        {
            j++
        }
        i++;
    }
}
int main(int argc, char ** argv)
{
}

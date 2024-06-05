#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
void readfile(int file, t_map map)
{
	
	char c[1];
	read(file,c,1);
	while(c[0]>='0' && c[0]<='9')
	{
		read(file,c,1);
	
	}
	map.rows=10;
	read(file,c,1);
	map.empt='-';
	read(file,c,1);
	map.obst='x';
	read(file,c,1);
	map.full='*';
	int i=0;
	int countcols;
	while(i<map.rows)
	{
		read(file,c,1);
		countcols=0;
		while(c[0]!='\n')
		{
			map.mat[i][countcols]=c[0];
			countcols++;
			read(file,c,1);
		}
		i++;
	}
	map.cols=countcols;
}
int get_square(int row, int col, t_map map, t_square sqr)
{	
	int i=0;
	int j=0;
	if(row == map.rows || col == map.cols)
		return sqr.size;
	while(i <sqr.size)
	{
		if(map.mat[i][col]!=map.empt)
			return sqr.size;
		i++;
	}
	while(j < sqr.size)
	{
		if(map.mat[row][j]!=map.empt)
			return sqr.size;
		j++;
	}
	if(map.mat[row][col]!=map.empt)
		return sqr.size;
	sqr.size++;
	row++;
	col++;
	sqr.size=get_square(row,col,map,sqr);
	return sqr.size;
}
t_square ft_cpy_sqr(t_square max_sqr, t_square sqr)
{
	max_sqr.x=sqr.x;
	max_sqr.y=sqr.y;
	max_sqr.size=sqr.size;
	return max_sqr;
}
t_square get_max_square(t_map map)
{
	int	row;
	int	col;
	t_square	max_sqr;
	t_square	sqr;
	
	max_sqr.x = -1;
	max_sqr.y = -1;
	max_sqr.size = 0;
	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.cols)
		{
			sqr.x = row;
			sqr.y = col;
			sqr.size=0;
			sqr.size=get_square(row,col,map,sqr);
			if (sqr.size > max_sqr.size)
			{
				max_sqr.size=sqr.size;
				max_sqr.x=sqr.x;
				max_sqr.y=sqr.y;
			}
			col++;
		}
		row++;
	}
	return max_sqr;
}
int main(int argc, char ** argv)
{
	int i;
	int j;
	t_map map;
	int file=open(argv[1],O_RDONLY);
	map.rows=100;
	map.cols=100;
	map.mat = (unsigned char**)malloc(sizeof(unsigned char*) * map.rows);
    for (i = 0; i < map.rows; i++) 
	{
        map.mat[i] = (unsigned char*)malloc(sizeof(unsigned char) * map.cols);
    }

	t_square sqrt_max=get_max_square(map);
	printf("%i\n",sqrt_max.x);
	printf("%i\n",sqrt_max.y);
	printf("%i\n",sqrt_max.size);
}

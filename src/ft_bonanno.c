#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
t_map  readfile(char file, t_map map)
{
	unsigned char c[1];
	int countcols = 0;
	map.rows=0;
	read(file,c,1);
	while(c[0]>='0' && c[0]<='9')
	{
		map.rows=map.rows*10+c[0]-'0';
		read(file,c,1);
	}
	printf("%i\n",map.rows);
	map.empt=c[0];
	write(1,&map.empt,1);
	write(1,"\t",1);
	read(file,c,1);
	map.obst=c[0];
	write(1,&map.obst,1);
	write(1,"\t",1);
	read(file,c,1);
	map.full=c[0];
	write(1,&map.full,1);
	write(1,"\n",1);
	read(file,c,1);
	while(c[0]=='\n')
	{
		read(file,c,1);
	}
	int i=0;
	while(i<map.rows)
	{
		countcols=0;
		while(c[0]!='\n')
		{
			map.mat[i][countcols]=c[0];
			read(file,c,1);
			countcols++;
		}
		read(file,c,1);
		i++;
	}
	map.cols=countcols;
	return map;
}
t_square get_square(int row, int col, t_map map, t_square sqr)
{	
	int i=0;
	int j=0;
	if(row == map.rows || col == map.cols)
		return sqr;
	while(i < sqr.size + 1)
	{
		if(map.mat[i][col]==map.obst)
		{
			return sqr;
		}
		i++;
	}
	while(j < sqr.size + 1)
	{
		if(map.mat[row][j]==map.obst)
		{
			return sqr;
		}
		j++;
	}
	if(map.mat[row][col]==map.obst)
		return sqr;
	row++;
	col++;
	sqr=get_square(row,col,map,sqr);
	sqr.size++;
	//printf("%i",sqr.size);
	return sqr;
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
			sqr.size = 0 ;
			sqr=get_square(row,col,map,sqr);
			//printf("\n");
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
unsigned char **changematrix(t_map map, t_square sqrt)
{
	int i = 0;
	int j = 0;
	while(i<sqrt.size)
	{
		j=0;
		while(j<sqrt.size)
		{
			map.mat[sqrt.x+i][sqrt.y+j]=map.full;
			//write(1,&map.mat[sqrt.x+i][sqrt.y+j],1);
			j++;
		}
		i++;
	}
	return map.mat;
}
void stampamatrice(t_map map)
{
	int i = 0;
	int j;
	write(1,"\n",1);
	while(i<map.rows)
	{
		j = 0;
		while(j<map.cols)
		{
			write(1,&map.mat[i][j],1);
			j++;
		}
		write(1,"\n",1);
		i++;
	}
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
	map=readfile(file,map);
	stampamatrice(map);
	t_square sqrt=get_max_square(map);
	//write(1,"\n",1);
	map.mat=changematrix(map,sqrt);
	stampamatrice(map);
	printf("\n%i\n",sqrt.x);
	printf("%i\n",sqrt.y);
	printf("%i\n",sqrt.size);
}

#include <stdlib.h>
#include "filler.h"

#include <stdio.h> //remove me

int	**makehmap(int my, int mx)
{
	int y;
	int x;
	int **map;

	map = (int**)malloc(sizeof(int*) * my);
	y = 0;
	while (y < my)
	{
		map[y] = (int*)malloc(sizeof(int) * mx);
		while (x < mx)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}

void	downandup(int n, int y, int x, f_list *node, int **hmap)
{
	int i;
	int j;

	i = n;
	j = -1;
	while ((--i > 0) && (++j < 24))
		if (((y - j) >= 0) && (node->map[y - j][x] == '.'))
		{
			if (hmap[y - j][x] < i)
				hmap[y - j][x] = i;
			if (node->map[y - j][x] == node->opp)
				break ;
			//hmap[y - j][x] = i;
		}
	i = n;
	j = -1;
	while ((--i > 0) && (++j < 24))
		if (((y + j) < node->map_y) && (node->map[y + j][x] == '.'))
		{
			if (hmap[y + j][x] < i)
				hmap[y + j][x] = i;
			if (node->map[y + j][x] == node->opp)
				break ;
			//hmap[y + j][x] = i;
		}
}

void	checkhmap(int **hmap, int y, int x, f_list *node)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 24;
	flag = 1;
	while (flag)
	{
		downandup(j, y, x - i, node, hmap);
		downandup(j, y, x + i, node, hmap);
		j--;
		i++;
		if (flag == 1)
		{
			if (j == 1)
			{
				flag = 2;
				i = 0;
				j = 23;
			}
		}
		else if (flag == 2)
			if (j == 1)
				break ;
	}
//	hmap[y][x] = 0;
}

void	printhmap(int **map, f_list *node)
{
	int y;
	int x;

	y = -1;
	while (++y < node->map_y)
	{
		x = -1;
		while (++x < node->map_x)
			fprintf(stderr, "%d", map[y][x]);
		fprintf(stderr, "\n");
	}
}

int	**hmap(f_list *node)
{
	int my;
	int mx;
	int x;
	int y;
	int **heatmap;

	mx = node->map_x;
	my = node->map_y;
	//create and initialize the map
	heatmap = makehmap(my, mx);
	//printhmap(heatmap, node);
	y = 0;
	while (y < my)
	{
		x = 0;
		while (x < mx)
		{
			//fprintf(stderr, "loop y = %d, x = %d\n", y, x);
			//fprintf(stderr, "map = %c opp = %c\n",node->map[y][x], node->opp);
			if (node->map[y][x] == node->opp)
			{
			//fprintf(stderr, "loop y = %d, x = %d\n", y, x);
				checkhmap(heatmap, y, x, node);
			}
			x++;
		}
		y++;
	}
//	printhmap(heatmap, *node);
	return (heatmap);
}

#include "filler.h"
#include <stdlib.h>
//#include <stdio.h>

char	**mapdup(f_list *node)
{
	char	**ret;
	int		y;
	int		x;

	y = -1;
	ret = (char**)malloc(sizeof(char*) * node->map_y);
	while (++y < node->map_y)
	{
		x = -1;
		ret[y] = (char*)malloc(sizeof(char) * node->map_x);
		while (++x < node->map_x)
			ret[y][x] = node->map[y][x];
	}
	return (ret);
}

char	**mapreset(f_list *node)
{
	char	**ret;
	int		y;
	int		x;

	y = -1;
	ret = (char**)malloc(sizeof(char*) * node->map_y);
	while (++y < node->map_y)
	{
		x = -1;
		ret[y] = (char*)malloc(sizeof(char) * node->map_x);
		while (++x < node->map_x)
		{
			if (node->oppm[y][x] == node->map[y][x] &&
				((node->oppm[y][x] != node->user) ||
				(node->oppm[y][x] != node->user + 32)))
				ret[y][x] = '.';
			else
				ret[y][x] = node->map[y][x];
		}
	}
//	free(node->oppm);
	return (ret);
}

void	oppmap(f_list **node)
{
	/*
		if ((*node)->oppm == NULL && (*node)->noppm == NULL)
		{
			(*node)->oppm = mapdup(*node);
			(*node)->noppm = mapdup(*node);
		}
*/		fprintf(stderr, "oppm map %d\n", (*node)->map_y);
//		printomap(*node, (*node)->oppm);
/*/		fprintf(stderr, "map\n");
//		printomap(*node, (*node)->map);
		fprintf(stderr, "noppm map\n");
		printomap(*node, (*node)->noppm);
		(*node)->noppm = mapreset(*node);
		findoppco(node);
		fprintf(stderr, "player = %c, opp y === %d,  opp x === %d\n",(*node)->opp, (*node)->opp_pos_y, (*node)->opp_pos_x);
		(*node)->oppm = mapdup(*node);*/
}

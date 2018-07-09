#include "filler.h"

void	scanfromtop(f_list **node)
{
	int y;
	int x;
	int flag;

	y = -1;
	flag = 1;
	while ((++y < (*node)->map_y) && flag)
	{
		x = -1;
		while ((++x < (*node)->map_x) && (flag))
		{
			if ((*node)->map[y][x] == (*node)->opp - 32)
			{
				(*node)->user_pos_y = y;
				(*node)->user_pos_x = x;
				flag = 0;
			}
		}
	}
}

void	scanfrombelow(f_list **node)
{
	int y;
	int x;
	int flag;

	y = (*node)->map_y;
	flag = 1;
	while ((--y >= 0) && (flag))
	{
		x = (*node)->map_x;
		while ((--x >= 0) && (flag))
		{
			if ((*node)->map[y][x] == (*node)->opp - 32)
			{
				(*node)->user_pos_y = y;
				(*node)->user_pos_x = x;
				flag = 0;
			}
		}
	}
}

void	findoppco(f_list **node)
{
	if ((*node)->opp == 'O')
	{
		scanfromtop(node);
	}
	else
	{
		scanfrombelow(node);
	}
}

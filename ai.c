#include "filler.h"

int		aidr(f_list **node, int *c)
{
	int y;
	int x;
	static int flag;

	flag = 0;
	y = 0;
	while ((*node)->map_y > y)
	{
		x = 0;
		while ((*node)->map_x > x)
		{
			if (try_token(node, y, x) && (*c <= (*node)->heatmap[y][x]))
			{
				*c = (*node)->heatmap[y][x];
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				flag = 1;
			}
			x++;
		}
		y++;
	}
	if (flag)
		return (1);
	else
	{
		*c = 0;
		return (0);
	}
}

int		aidl(f_list **node, int *c)
{
	int y;
	int x;

	y = 0;
	while ((*node)->map_y > y)
	{
		x = (*node)->map_x;
		while (x)
		{
			if (try_token(node, y, x) && (*c <= (*node)->heatmap[y][x]))
			{
				*c = (*node)->heatmap[y][x];
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
			}
			x--;
		}
		y++;
	}
	return (1);
}

int		aiul(f_list **node, int *c)
{
	int y;
	int x;

	y = (*node)->map_y;
	while (y)
	{
		x = (*node)->map_x;
		while (x)
		{
			if (try_token(node, y, x) && (*c <= (*node)->heatmap[y][x]))
			{
				*c = (*node)->heatmap[y][x];
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
			}
			x--;
		}
		y--;
	}
	return (1);
}

int		aiur(f_list **node, int *c)
{
	int y;
	int x;

	y = (*node)->map_y;
	while (y)
	{
		x = 0;
		while (x < (*node)->map_x)
		{
			if (try_token(node, y, x) && (*c <= (*node)->heatmap[y][x]))
			{
				*c = (*node)->heatmap[y][x];
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
			}
			x++;
		}
		y--;
	}
	return (1);
}

int	ai(f_list **node)
{
	int c;

	c = 0;
	(*node)->heatmap = hmap(*node);
	if ((*node)->calc == 0)
	{
		if (aidr(node, &c));
		else 
			aidl(node, &c);
	}
	else if ((*node)->calc == 1)
	{
		(aiul(node, &c));
	}
	else if ((*node)->calc == 2)
	{
		(aiur(node, &c));
	}
	else if((*node)->calc == 3)
	{
		(aidl(node, &c));
	}
	return (1);
}

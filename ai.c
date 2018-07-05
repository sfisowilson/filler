#include "filler.h"

int		aidr(f_list **node)
{
	int y;
	int x;

	y = 0;
	while ((*node)->map_y > y)
	{
		x = 0;
		while ((*node)->map_x > x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				if (ft_strchr((*node)->map[y], '*'))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int		aidl(f_list **node)
{
	int y;
	int x;

	y = 0;
	while ((*node)->map_y > y)
	{
		x = (*node)->map_x;
		while (x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				if (ft_strchr((*node)->map[y], '*'))
					return (1);
			}
			x--;
		}
		y++;
	}
	return (1);
}

int		aiul(f_list **node)
{
	int y;
	int x;

	y = (*node)->map_y;
	while (y)
	{
		x = (*node)->map_x;
		while (x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				if (ft_strchr((*node)->map[y], '*'))
					return (1);
			}
			x--;
		}
		y--;
	}
	return (1);
}

int		aiur(f_list **node)
{
	int y;
	int x;

	y = (*node)->map_y;
	while (y)
	{
		x = 0;
		while (x < (*node)->map_x)
		{
			if (try_token(node, y, x))
			{
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				if (ft_strchr((*node)->map[y], '*'))
				{
					fprintf(stderr, "close __ y = %d, x = %d\n", y, x);
					return (1);
				}
			}
			x++;
		}
		y--;
	}
	return (1);
}

int	ai(f_list **node)
{
	int **heatmap;

	heatmap = hmap(*node);
	printhmap(heatmap, *node);
	if ((*node)->calc == 0)
	{
		fprintf(stderr, "down right\n");
		(aidr(node));
	}
	else if ((*node)->calc == 1)
	{
		fprintf(stderr, "up left\n");
		(aiul(node));
	}
	else if ((*node)->calc == 2)
	{
		fprintf(stderr, "up right\n");
		(aiur(node));
	}
	else if((*node)->calc == 3)
	{
		fprintf(stderr, "down left\n");
		(aidl(node));
	}
	return (1);
}

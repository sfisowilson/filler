#include "filler.h"
//#include <stdio.h>

int	checkd(int y, int x, f_list *node, int *c)
{
	int r;
	if ((node->opp_pos_y > y) && (node->opp_pos_x > x))
	{
		r = (y + node->opp_pos_y) + (x + node->opp_pos_x);
		if (*c < r)
		{	*c = r;
			return (1);
		}
	}
	else if ((node->opp_pos_y < y) && (node->opp_pos_x < x))
	{
		r = (y + node->opp_pos_y) + (x + node->opp_pos_x);
		if (*c > r)
		{
			*c = r;
			return (1);
		}
	}
	return (0);
	//sould compare with c and return 1 0r 0
}

int		aidr(f_list **node, int *c)
{
	int y;
	int x;
	static int flag;

	flag = 0;
	y = 0;
	fprintf(stderr, "c start == %d\n", *c);
	while ((*node)->map_y > y)
	{
		x = 0;
		while ((*node)->map_x > x)
		{
//	fprintf(stderr, "c before  == %d\n", *c);
			if (try_token(node, y, x) && (checkd(y, x, *node, c)))
			{
	fprintf(stderr, "c after == %d\n", *c);
	fprintf(stderr, "y = %d, x = %d, opy = %d, opx = %d\n", y, x, (*node)->opp_pos_y, (*node)->opp_pos_x);
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				flag = 1;
			}
			x++;
		}
		y++;
	}
	
	fprintf(stderr, "c final == %d\n", *c);
	if (flag)
		return (1);
	else
	{

		*c = 0;
		return (0);
	}
}
/*
int		aidl(f_list **node, int *c)
{
	int y;
	int x;
	static int flag;

	flag = 0;
	y = 0;
	while ((*node)->map_y > y)
	{
		x = (*node)->map_x;
		while (--x >= 0)
		{
//	fprintf(stderr, "c before  == %d\n", *c);
			if (try_token(node, y, x) && (*c < checkd(y, x, *node)))
			{
	fprintf(stderr, "c after == %d\n", *c);
	fprintf(stderr, "y = %d, x = %d, opy = %d, opx = %d\n", y, x, (*node)->opp_pos_y, (*node)->opp_pos_x);
				*c = checkd(y, x, *node);
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				flag = 1;
			}
		}
		y++;
	}
	fprintf(stderr, "c final == %d\n", *c);
	if (flag)
		return (1);
	else
	{
		*c = 0;
		return (0);
	}
}
int		aiur(f_list **node, int *c)
{
	int y;
	int x;
	static int flag;

	flag = 0;
	y = (*node)->map_y;
	while (--y >= 0)
	{
		x = 0;
		while ((*node)->map_x > x)
		{
//	fprintf(stderr, "c before  == %d\n", *c);
			if (try_token(node, y, x) && (*c < checkd(y, x, *node)))
			{
	fprintf(stderr, "c after == %d\n", *c);
	fprintf(stderr, "y = %d, x = %d, opy = %d, opx = %d\n", y, x, (*node)->opp_pos_y, (*node)->opp_pos_x);
				*c = checkd(y, x, *node);
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				flag = 1;
			}
			x++;
		}
	}
	fprintf(stderr, "c final == %d\n", *c);
	if (flag)
		return (1);
	else
	{
		*c = 0;
		return (0);
	}
}
int		aiul(f_list **node, int *c)
{
	int y;
	int x;
	static int flag;

	flag = 0;
	y = (*node)->map_y;
	while (--y >= 0)
	{
		x = (*node)->map_x;
		while (--x >= 0)
		{
//	fprintf(stderr, "c before  == %d\n", *c);
			if (try_token(node, y, x) && (*c < checkd(y, x, *node)))
			{
	fprintf(stderr, "c after == %d\n", *c);
	fprintf(stderr, "y = %d, x = %d, opy = %d, opx = %d\n", y, x, (*node)->opp_pos_y, (*node)->opp_pos_x);
				*c = checkd(y, x, *node);
				(*node)->play_y = y - (*node)->st_y;
				(*node)->play_x = x - (*node)->st_x;
				flag = 1;
			}
		}
	}
	fprintf(stderr, "c final == %d\n", *c);
	if (flag)
		return (1);
	else
	{
		*c = 0;
		return (0);
	}
}*/
/*
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
*/
int	ai(f_list **node)
{
	int c;

	if (((*node)->opp_pos_y > (*node)->user_pos_y) && ((*node)->opp_pos_x > (*node)->user_pos_x))
		c = 0;
	else if (((*node)->opp_pos_y < (*node)->user_pos_y) && ((*node)->opp_pos_x < (*node)->user_pos_x))
		c = 1000;
//	fprintf(stderr, "before call----------------------\n");
//	(*node)->heatmap = hmap(*node);
//	if ((*node)->calc == 0)
//	{
	aidr(node, &c);
//	aidl(node, &c);
//	aiul(node, &c);
//	aiur(node, &c);
//		else 
//			aidl(node, &c);
//	}
/*	else if ((*node)->calc == 1)
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
	}*/
	return (1);
}

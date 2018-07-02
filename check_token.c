#include "filler.h"
#include <stdlib.h>

int	check_token(f_list **node, int my, int mx)
{
	int	y;
	int	x;
	int	sy;
	int	sx;
	int	shell_try;
	
	sy = (*node)->st_y;
	sx = (*node)->st_x;
	y =0;
	shell_try = 0;
	while ((*node)->token_y > y + sy)
	{
		x = 0;
		while ((*node)->token_x > x + sx)
		{
			if ((((*node)->map[my + y][mx + x] == (*node)->user) ||\
				(*node)->map[my + y][mx + x] == (*node)->user + 32) &&\
				((*node)->token[y + sy][x + sx] == '*'))
				shell_try++;
			if ((((*node)->map[my + y][mx + x] == (*node)->opp) ||\
				(*node)->map[my + y][mx +  x] == (*node)->opp + 32) &&\
				((*node)->token[y + sy][x + sx] == '*'))
				return (0);
			x++;
		}
		y++;
	}
	return ((shell_try == 1)? 1 : 0);
}

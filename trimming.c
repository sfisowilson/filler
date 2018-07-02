#include "filler.h"

void	trim_height(f_list **node)
{
	int y;

	y = 0;
	while (y < (*node)->token_y)
	{
		if (ft_strchr((*node)->token[y], '*'))
		{
			(*node)->t_y = 0;
			(*node)->st_y = y;
			while (y < (*node)->token_y)
			{
				if (!ft_strchr((*node)->token[y], '*'))
					break ;
				(*node)->t_y++;
				y++;
			}
			break ;
		}
		y++;
	}
}

void	trim_width(f_list **node)
{
	int y;
	int x;

	y = (*node)->st_y;
	(*node)->st_x = (*node)->token_x;
	(*node)->t_x = 0;

	while (y < (*node)->token_y)
	{
		x = 0;
		while (x < (*node)->token_x)
		{
			if ((*node)->token[y][x] == '*')
			{
				if (x > (*node)->t_x)
					(*node)->t_x = x;
				if (x < (*node)->st_x)
					(*node)->st_x = x;
			}
			x++;
		}
		y++;
	}
	(*node)->t_x = ((*node)->t_x - (*node)->st_x) + 1;
}

void	trimming(f_list **node)
{
	trim_height(node);
	trim_width(node);
	(*node)->token_y = (*node)->st_y + (*node)->t_y;
	(*node)->token_x = (*node)->st_x + (*node)->t_x;
}

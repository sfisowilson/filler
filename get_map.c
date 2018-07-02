#include "filler.h"
#include <stdlib.h>

void	set_calc(f_list **node);

char	*get_map(f_list **node, char *line)
{
	int i;
	int	len;
	int	j;
	
//	fprintf(stderr, "first line in get map == %s\n", line);
	i = 0;
	if ((line)[0] == ' ')
		get_next_line(0, &line);
	len = ft_strlen(line) - 4;
	(*node)->map  = (char **)malloc(sizeof(char *) * (*node)->map_y);
	while ((*node)->map_y > i)
	{
		(*node)->map[i] = ft_strsub((line) + 4, 0, len);
		if (ft_strchr((*node)->map[i], (*node)->user))
		{
			j = 0;
			while ((*node)->map[i][j] != (*node)->user)
				j++;
			(*node)->user_pos_y = i;
			(*node)->user_pos_x = j;
		}

//		fprintf(stderr, "%i line added to map == %s\n", i, (*node)->map[i]);
		get_next_line(0, &line);
		i++;
	}
	set_calc(node);
//	fprintf(stderr, "line returned from  map == %s\n", line);
	return (line);
}
void	get_possition(f_list **node)
{
	int y;
	int x;

	y = 0;
	while ((*node)->map_y > y)
	{
		if (ft_strchr((*node)->map[y], (*node)->user))
		{
			x = 0;
			while ((*node)->map[y][x] != (*node)->user)
				x++;
			(*node)->user_pos_y = y;
			(*node)->user_pos_x = x;
		}
		else if (ft_strchr((*node)->map[y], (*node)->opp))
		{
			x = 0;
			while ((*node)->map[y][x] != (*node)->opp)
				x++;
			(*node)->opp_pos_y = y;
			(*node)->opp_pos_x = x;
		}
		y++;
	}
}

void set_calc(f_list **node)
{
	get_possition(node);
	if (((*node)->user_pos_y) > ((*node)->opp_pos_y))
	{
		if ((*node)->calc == 1)
			(*node)->calc = 2;
		else  if ((*node)->calc == 2)
			(*node)->calc = 1;
		else
			(*node)->calc = 1;
	}
	else if (((*node)->user_pos_y) < ((*node)->opp_pos_y))
	{
		if ((*node)->calc == 0)
			(*node)->calc = 3;
		else  if ((*node)->calc == 3)
			(*node)->calc = 0;
		else
			(*node)->calc = 0;
	}
}

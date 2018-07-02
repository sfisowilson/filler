#include "filler.h"
#include <stdlib.h>

int	main(void)
{
	f_list	*node;
	char	*line;


	node = (f_list*)malloc(sizeof(f_list));
	get_next_line(0, &line);
	if (get_players(&node, line))
		node->opp = (node->user == 'O')? 'X' : 'O';
	while (1)
	{
		get_next_line(0, &line);
		if (get_mapsize(&node, line))
			get_next_line(0, &line);
		line = get_map(&node, line);
		get_tokensize(&node, line);
		get_next_line(0, &line);
		line = get_token(&node, line);
		trimming(&node);
		if(ai(&node))
		{
			reply(&node);
		}
		else
			reply_end();
	}
	return (0);
}

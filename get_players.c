#include "filler.h"

int	get_players(f_list **node, char *line)
{
	if (line[0] == '$')
		(*node)->user = (line[10] == '1')? 'O' : 'X';
	else
		return (0);
	return (1);
}

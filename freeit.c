#include "filler.h"
#include <stdlib.h>

void	freeit(f_list **node)
{
	//free map
	int i;

	i = 0;
	while ((*node)->map_y > i)
	{
		free((*node)->map[i]);
		i++;
	}
	free((*node)->map);
	i = 0;
	while ((*node)->token_y > i)
	{
		free((*node)->token[i]);
		i++;
	}
	free((*node)->token);
	//free token
	//free line
}

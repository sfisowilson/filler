#include "filler.h"
#include <stdlib.h>

int	try_token(f_list **node, int my, int mx)
{
	//fprintf(stderr, "trying token with my = %i and mx = %i\n", my, mx);
	if (my + (*node)->t_y > (*node)->map_y)
	{
		return (0);
	}
	if (mx + (*node)->t_x > (*node)->map_x)
	{
	//	fprintf(stderr, "returning 0 try_token failed\n");
		return (0);
	}
//	fprintf(stderr, "returning 0 try_token failed\n");
	return (check_token(node, my, mx));
}

#include "filler.h"
#include <stdlib.h>

char	*get_token(f_list **node, char *line)
{
	int i;
	int	len;
	i = 0;
	len = ft_strlen(line);
	(*node)->token  = (char **)malloc(sizeof(char *) * (*node)->token_y);
	while ((*node)->token_y > i)
	{
		(*node)->token[i] = ft_strsub(line, 0, len);
	//	fprintf(stderr, "%i line added to token = %s\n", i, (*node)->token[i]);
		if (i != ((*node)->token_y - 1))
			get_next_line(0, &line);
		i++;
	}
	return (line);
}

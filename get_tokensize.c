#include "filler.h"

int	get_tokensize(f_list **node, char *line)
{
	int i;
	int j;

	i = 0;
	if (line[i] == 'P')
	{
		while (!ft_isdigit(line[i]))
			i++;
		j = 0;
		while (ft_isdigit(line[i + j]))
			j++;
		(*node)->token_y = ft_atoi(ft_strsub(line, i, i + j));
		i = i + j + 1;
		j = 0;
		while (ft_isdigit(line[i + j]))
			j++;
		(*node)->token_x = ft_atoi(ft_strsub(line, i, i + j));
		return (1);
	}
	return (0);
}

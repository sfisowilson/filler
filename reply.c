#include "filler.h"

void	reply(f_list **node)
{
	if ((*node)->calc == 0)
		(*node)->calc = 3;
	else if ((*node)->calc == 1)
		(*node)->calc = 2;
	else if ((*node)->calc == 3)
		(*node)->calc = 0;
	else if ((*node)->calc == 2)
		(*node)->calc = 1;
	ft_putnbr((*node)->play_y);
	ft_putchar(' ');
	ft_putnbr((*node)->play_x);
	ft_putchar('\n');
	freeit(node);
}

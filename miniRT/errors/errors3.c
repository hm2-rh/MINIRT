#include "../minirt.h"

void	unrecognized_id(char **tab)
{
	ft_putstr_fd("Error\nUnrecognized id: ", 1);
		ft_putstr_fd(tab[0], 1);
		ft_putchar_fd('\n', 1);
		exit(-1);
}
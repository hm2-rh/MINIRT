#include "minirt.h"

int    tab_len(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int     is_whitespace(int c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (-1);
}
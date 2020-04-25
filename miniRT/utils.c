/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:55:31 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:55:32 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

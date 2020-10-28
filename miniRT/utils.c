/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:55:31 by hrhirha           #+#    #+#             */
/*   Updated: 2020/10/14 11:56:59 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	lst_circle(t_list **imgs)
{
	t_list *last;

	last = *imgs;
	while (last)
	{
		if (last->next == NULL)
		{
			last->next = *imgs;
			break ;
		}
		last = last->next;
	}
}

int		tab_len(char **tab)
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

void	free_and_exit(char **tab)
{
	free_tab(tab);
	exit(-1);
}

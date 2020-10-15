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

int		keys(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == ESC_KEY)
		exit(EXIT_SUCCESS);
	if (key == SP_KEY)
	{
		data->imgs = data->imgs->next;
		data->curr_img = data->imgs->content;
		mlx_put_image_to_window(data->ptr, data->win, data->curr_img->img, 0, 0);
	}
	return (key);
}

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

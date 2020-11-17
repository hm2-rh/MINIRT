/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:55:20 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:55:22 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	init(t_data *data)
{
	data->lights = NULL;
	data->shapes = NULL;
	data->cams = NULL;
	data->res.loaded = -1;
	data->amb.loaded = -1;
}

char	*rm_tabs(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
		i++;
	}
	return (line);
}

void	implement(t_data *data, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	while (is_whitespace(*line) == 1)
		line += 1;
	tab = ft_split(line, ' ');
	if (!tab[0] || tab[0][0] == '#')
		free_tab(tab);
	else if (ft_strcmp(tab[0], "sp") == 0 ||
		ft_strcmp(tab[0], "pl") == 0 ||
		ft_strcmp(tab[0], "tr") == 0 ||
		ft_strcmp(tab[0], "sq") == 0 ||
		ft_strcmp(tab[0], "cy") == 0)
		implement_shapes(tab, &data->shapes);
	else if (ft_strcmp(tab[0], "R") == 0)
		implement_res(data, tab, &data->res);
	else if (ft_strcmp(tab[0], "A") == 0)
		implement_amb(tab, &data->amb);
	else if (ft_strcmp(tab[0], "c") == 0)
		implement_cameras(tab, &data->cams);
	else if (ft_strcmp(tab[0], "l") == 0)
		implement_lights(tab, &data->lights);
	else
		unrecognized_id(tab);
}

void	read_fd(int fd, t_data *data)
{
	char *line;

	init(data);
	while (get_next_line(fd, &line))
	{
		line = rm_tabs(line);
		implement(data, line);
		free(line);
	}
	implement(data, line);
	free(line);
}

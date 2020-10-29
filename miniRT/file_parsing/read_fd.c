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
	int i;

	i = 0;
	while (is_whitespace(*line) == 1)
		line += 1;
	if ((line[0] == 's' && line[1] == 'p' && is_whitespace(line[2]) == 1) ||
		(line[0] == 'p' && line[1] == 'l' && is_whitespace(line[2]) == 1) ||
		(line[0] == 't' && line[1] == 'r' && is_whitespace(line[2]) == 1) ||
		(line[0] == 's' && line[1] == 'q' && is_whitespace(line[2]) == 1) ||
		(line[0] == 'c' && line[1] == 'y' && is_whitespace(line[2]) == 1))
		implement_shapes(line, &data->shapes);
	if (line[0] == 'R' && is_whitespace(line[1]) == 1)
		implement_res(line, &data->res);
	if (line[0] == 'A' && is_whitespace(line[1]) == 1)
		implement_amb(line, &data->amb);
	if (line[0] == 'c' && is_whitespace(line[1]) == 1)
		implement_cameras(line, &data->cams);
	if (line[0] == 'l' && is_whitespace(line[1]) == 1)
		implement_lights(line, &data->lights);
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

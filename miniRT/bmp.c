/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:52:26 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:52:32 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <time.h>

void	set_bmp(t_bmp *bmp, t_data *data)
{
	bmp->type[0] = 0x42;
	bmp->type[1] = 0x4D;
	bmp->size = 54 + data->res.w * data->res.h * 3;
	bmp->reserve = 0;
	bmp->offset = 54;
	bmp->dib_size = 40;
	bmp->width = data->res.w;
	bmp->height = data->res.h;
	bmp->plane = 1;
	bmp->bpp = 24;
	bmp->copmression = 0;
	bmp->array_size = data->res.w * data->res.h * 3;
	bmp->x_res = 2835;
	bmp->y_res = 2835;
	bmp->colour = 0;
	bmp->imp_colour = 0;
}

void	write_header(const int fd, t_bmp *bmp)
{
	write(fd, &(bmp->type), 2);
	write(fd, &(bmp->size), 4);
	write(fd, &(bmp->reserve), 4);
	write(fd, &(bmp->offset), 4);
	write(fd, &(bmp->dib_size), 4);
	write(fd, &(bmp->width), 4);
	write(fd, &(bmp->height), 4);
	write(fd, &(bmp->plane), 2);
	write(fd, &(bmp->bpp), 2);
	write(fd, &(bmp->copmression), 4);
	write(fd, &(bmp->array_size), 4);
	write(fd, &(bmp->x_res), 4);
	write(fd, &(bmp->y_res), 4);
	write(fd, &(bmp->colour), 4);
	write(fd, &(bmp->imp_colour), 4);
}

char	*get_current_time_name(void)
{
	time_t		t;
	struct tm	*info;
	size_t		str_len;
	char		*str;

	time(&t);
	info = localtime(&t);
	str = ft_strdup("screenshot_");
	str_len = strftime(str + 11, 39, "%F-%T", info);
	return (str);
}

int		save_image(t_data *data, int x, int y)
{
	t_bmp	bmp;
	int		fd;
	char	*add;
	char	*name;
	char 	*tmp;

	ft_putstr_fd("Saving...\n", 0);
	add = (char *)data->addr;
	set_bmp(&bmp, data);
	tmp = get_current_time_name();
	name = ft_strjoin(tmp, ".bmp");
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	free(tmp);
	free(name);
	write_header(fd, &bmp);
	y = data->res.h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->res.w)
		{
			write(fd, &(add[(y * data->res.w + x) * 4]), 3);
			x++;
		}
		y--;
	}
	close(fd);
	ft_putstr_fd("Done!\n", 0);
	return (0);
}

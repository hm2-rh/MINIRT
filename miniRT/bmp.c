/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:52:26 by hrhirha           #+#    #+#             */
/*   Updated: 2020/11/15 13:51:47 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_bmp(t_bmp *bmp, t_data *data)
{
	bmp->type[0] = 'B';
	bmp->type[1] = 'M';
	bmp->size = 54 + data->res.w * data->res.h * 3;
	bmp->reserve = 0;
	bmp->offset = 54;
	bmp->header_size = 40;
	bmp->iwidth = data->res.w;
	bmp->iheight = data->res.h;
	bmp->plane = 1;
	bmp->bpp = 24;
	bmp->compression = 0;
	bmp->img_size = 0;
	bmp->x_res = 0;
	bmp->y_res = 0;
	bmp->total_color = 0;
	bmp->important_color = 0;
}

void	write_header(const int fd, t_bmp *bmp)
{
	write(fd, &(bmp->type), 2);
	write(fd, &(bmp->size), 4);
	write(fd, &(bmp->reserve), 4);
	write(fd, &(bmp->offset), 4);
	write(fd, &(bmp->header_size), 4);
	write(fd, &(bmp->iwidth), 4);
	write(fd, &(bmp->iheight), 4);
	write(fd, &(bmp->plane), 2);
	write(fd, &(bmp->bpp), 2);
	write(fd, &(bmp->compression), 4);
	write(fd, &(bmp->img_size), 4);
	write(fd, &(bmp->x_res), 4);
	write(fd, &(bmp->y_res), 4);
	write(fd, &(bmp->total_color), 4);
	write(fd, &(bmp->important_color), 4);
}

int		save_image(t_data *data)
{
	int		x;
	int		y;
	t_bmp	bmp;
	int		fd;
	char	*add;

	ft_putstr_fd("Saving...\n", 1);
	add = (char *)data->curr_img->addr;
	set_bmp(&bmp, data);
	data->bmp_name = "scene.bmp";
	fd = open(data->bmp_name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write_header(fd, &bmp);
	y = data->res.h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x++ < data->res.w)
		{
			write(fd, &(add[(y * data->res.w + x) * 4]), 3);
		}
		y--;
	}
	close(fd);
	ft_putstr_fd("\nImage saved as: scene.bmp\n", 1);
	return (0);
}

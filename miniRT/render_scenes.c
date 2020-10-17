/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:55:10 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:55:13 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pixel_to_img(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->curr_img->addr + (y * data->curr_img->line_len + x * (data->curr_img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ray_trace(t_data *data)
{
	int		x;
	int		y;
	double	px;
	double	py;
	double	angle;

	data->curr_cam = data->cams->content;
	data->ray.start = data->curr_cam->pos;
	y = 0;
	while (y < data->res.h)
	{
		x = 0;
		while (x < data->res.w)
		{
			angle = tan((data->curr_cam->fov / 2) * M_PI / 180);
			px = (2.0 * ((x + .5) / (double)data->res.w) - 1) *
				(angle * data->res.w / data->res.h);
			py = (2.0 * ((y + .5) / (double)data->res.h) - 1) * angle;
			data->pxl_color = calc_color(data, px, py);
			pixel_to_img(data, x, y, rgb_to_int(data->pxl_color));
			x++;
		}
		y++;
	}
}

void	render_scenes(t_data *data)
{
	t_list	*tmp_cam;
	t_list	*tmp_img;
	t_img	*new_img;

	tmp_cam = data->cams;
	while (tmp_cam)
	{
		new_img = malloc(sizeof(t_img));
		new_img->img = mlx_new_image(data->ptr, data->res.w, data->res.h);
		new_img->addr = mlx_get_data_addr(new_img->img, &new_img->bpp, &new_img->line_len,
										&new_img->endian);
		ft_lstadd_back(&data->imgs, ft_lstnew(new_img));
		tmp_cam = tmp_cam->next;
	}
	tmp_cam = data->cams;
	tmp_img = data->imgs;
	int i = 0;
	while (data->cams)
	{
		printf("rendering scene %d\n", i++);
		data->curr_img = (t_img *)(tmp_img->content);
		ray_trace(data);
		if (data->save == 1)
		{
			save_image(data, 0, 0);
			exit(EXIT_SUCCESS);
		}
		data->cams = data->cams->next;
		tmp_img = tmp_img->next;
	}
	data->cams = tmp_cam;
}

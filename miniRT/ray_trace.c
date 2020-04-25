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

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
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

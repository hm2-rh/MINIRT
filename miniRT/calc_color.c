/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:52:58 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:53:02 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		rgb_to_int(t_color c)
{
	return (c.r << 16 | c.g << 8 | c.b);
}

void	range_color(t_color *color)
{
	if (color->r < 0)
		color->r = 0;
	if (color->r > 255)
		color->r = 255;
	if (color->g < 0)
		color->g = 0;
	if (color->g > 255)
		color->g = 255;
	if (color->b < 0)
		color->b = 0;
	if (color->b > 255)
		color->b = 255;
}

void	intensity_value(t_data *data, t_vec n, t_vec light_dir,
						t_color *intensity)
{
	double	d2;

	d2 = dot(subvec(data->light->pos, data->hit_pt),
					subvec(data->light->pos, data->hit_pt));
	if (data->hit_lt != -1 && data->hit_lt > T_MIN
			&& data->hit_lt * data->hit_lt < d2)
		;
	else
	{
		intensity->r += data->light->ratio * data->light->color.r *
						dot(n, light_dir);
		intensity->g += data->light->ratio * data->light->color.g *
						dot(n, light_dir);
		intensity->b += data->light->ratio * data->light->color.b *
						dot(n, light_dir);
	}
}

t_color	calc_intensity(t_data *data, t_vec inter_pt, t_vec n)
{
	t_color	intensity;
	t_ray	tmp;
	t_list	*tmp_lt;

	intensity = (t_color){data->amb.ratio * data->amb.color.r,
						data->amb.ratio * data->amb.color.g,
						data->amb.ratio * data->amb.color.b};
	tmp_lt = data->lights;
	while (tmp_lt)
	{
		data->light = tmp_lt->content;
		data->ray_lt.start = addvec(inter_pt, mulvec(.0000001, n));
		data->ray_lt.dir = normalize(subvec(data->light->pos, inter_pt));
		tmp = data->ray;
		data->ray = data->ray_lt;
		data->hit_lt = first_inter(data, &data->hit_pt_lt, &data->hit_normal_lt,
									&data->hit_color_lt);
		intensity_value(data, n, data->ray_lt.dir, &intensity);
		tmp_lt = tmp_lt->next;
		data->ray = tmp;
	}
	return (intensity);
}

t_color	calc_color(t_data *data, double px, double py)
{
	t_color	intensity;
	t_color	col;

	col = (t_color){0, 0, 0};
	data->ray.dir = addvec(data->curr_cam->dir, addvec(
		mulvec(px, data->curr_cam->right), mulvec(py, data->curr_cam->down)));
	data->ray.dir = normalize(data->ray.dir);
	data->hit = first_inter(data, &data->hit_pt, &data->hit_normal,
							&data->hit_color);
	if (data->hit != -1 && data->hit > T_MIN)
	{
		intensity = calc_intensity(data, data->hit_pt, data->hit_normal);
		range_color(&intensity);
		col.r = intensity.r * data->hit_color.x;
		col.g = intensity.g * data->hit_color.y;
		col.b = intensity.b * data->hit_color.z;
	}
	return (col);
}

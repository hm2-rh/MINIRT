/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:54:21 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:54:23 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	plane_intersect(t_ray ray, t_plane pl)
{
	double denom;
	double t;

	denom = dot(ray.dir, pl.normal);
	if (denom >= 0)
		return (-1);
	t = dot(subvec(pl.ref, ray.start), pl.normal) / denom;
	return (t);
}

void	closest_pl(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double	t;
	t_plane	pl;

	pl = *(t_plane *)data->curr_shape;
	t = plane_intersect(data->ray, pl);
	if (t != -1 && t < data->t_min)
	{
		*col = pl.color;
		data->t_min = t;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = pl.normal;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:19:31 by hrhirha           #+#    #+#             */
/*   Updated: 2020/10/17 10:19:33 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	square_intersect(t_ray ray, t_sq sq)
{
	double	t;
	double	denom;

	denom = dot(ray.dir, sq.normal);
	if (denom >= 0)
		return (-1);
	t = dot(subvec(sq.center, ray.start), sq.normal) / denom;
	return (t);
}

void    closest_sq(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double	t;
	t_sq	sq;

	sq = *(t_sq *)data->curr_shape;
	t = square_intersect(data->ray, sq);
	if (t < data->t_min)
	{
		data->t_min = t;
		*col = sq.color;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = sq.normal;
	}
}

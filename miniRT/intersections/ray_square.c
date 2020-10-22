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
	t_vec	pt;
	t_vec	c_pt;
	double	dotu;
	double	dotv;

	denom = dot(ray.dir, sq.normal);
	if (denom == 0)
		return (-1);
	t = dot(subvec(sq.center, ray.start), sq.normal) / denom;
	if (t < T_MIN)
		return (-1);
	pt = addvec(ray.start, mulvec(t, ray.dir));
	c_pt = subvec(sq.center, pt);
	dotu = dot(c_pt, sq.u);
	dotv = dot(c_pt, sq.v);
	if (fabs(dotu) > sq.side / 2 ||
		fabs(dotv) > sq.side / 2)
		return (-1);
	return (t);
}

void    closest_sq(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double	t;
	t_sq	sq;

	sq = *(t_sq *)data->curr_shape;
	t = square_intersect(data->ray, sq);
	if (t!= -1 && t < data->t_min)
	{
		data->t_min = t;
		*col = sq.color;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = sq.normal;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:54:28 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:54:29 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vec	g_n;
t_vec	g_rp0;
double	g_den;
double	g_t;
t_vec	g_p;
double	g_u;
double	g_v;
double	g_w;

double	triangle_intersect(t_ray ray, t_tr tr)
{
	g_n = cross(tr.p0p1, tr.p0p2);
	g_rp0 = subvec(ray.start, tr.p0);
	g_den = dot(ray.dir, g_n);
	if (g_den == 0)
		return (-1);
	g_t = dot(invec(g_rp0), g_n) / g_den;
	if (g_t < T_MIN)
		return (-1);
	g_p = addvec(ray.start, mulvec(g_t, ray.dir));
	g_u = dot(cross(subvec(tr.p1, tr.p0), subvec(g_p, tr.p0)), g_n);
	g_v = dot(cross(subvec(tr.p2, tr.p1), subvec(g_p, tr.p1)), g_n);
	g_w = dot(cross(subvec(tr.p0, tr.p2), subvec(g_p, tr.p2)), g_n);
	if (g_u <= T_MIN || g_v <= T_MIN || g_w <= T_MIN)
		return (-1);
	return (g_t);
}

void	closest_tr(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double	t;
	t_tr	tr;

	tr = *(t_tr *)data->curr_shape;
	t = triangle_intersect(data->ray, tr);
	if (t != -1 && t < data->t_min - T_MIN)
	{
		data->t_min = t;
		*col = tr.color;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = normalize(cross(tr.p0p1, tr.p0p2));
		if (dot(*n, data->ray.dir) > 0)
			*n = invec(*n);
	}
}

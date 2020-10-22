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

double	g_t;
double	g_u;
double	g_v;
t_vec	g_p;
t_vec	g_q;
double	g_det;
double	g_invdet;
t_vec	g_rp0;

double	triangle_intersect(t_ray ray, t_tr tr)
{
	g_p = cross(ray.dir, tr.p0p2);
	g_det = dot(tr.p0p1, g_p);
	if (g_det > -T_MIN && g_det < T_MIN)
		return (-1);
	g_invdet = 1 / g_det;
	g_rp0 = subvec(ray.start, tr.p0);
	g_u = g_invdet * dot(g_rp0, g_p);
	g_q = cross(g_rp0, tr.p0p1);
	g_v = g_invdet * dot(ray.dir, g_q);
	if (g_u < 0 || g_u > 1 || g_v < 0 || g_u + g_v > 1)
		return (-1);
	g_t = g_invdet * dot(tr.p0p2, g_q);
	if (g_t < 0)
		return (-1);
	return (g_t);
}

void	closest_tr(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double	t;
	t_tr	tr;

	tr = *(t_tr *)data->curr_shape;
	t = triangle_intersect(data->ray, tr);
	if (t != -1 && t < data->t_min)
	{
		*col = tr.color;
		data->t_min = t;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = normalize(cross(tr.p0p1, tr.p0p2));
		if (n->z > 0)
			*n = invec(*n);
	}
}

#include "../minirt.h"

double	g_a;
double	g_b;
double	g_c;
double	g_disc;
double	g_t1;
double	g_t2;

t_vec	get_normal(t_vec p, t_cy cy)
{
	t_vec	c0;
	t_vec	v;
	t_vec	cyp;
	t_vec	cy2p;
	double	d;

	cyp = subvec(p, cy.pos);
	cy2p = subvec(p, cy.pos2);
	if (dot(cy.normal, cyp) == 0 && dot(cyp, cyp) <= cy.radius * cy.radius)
		return (invec(cy.normal));
	if (dot(cy.normal, cy2p) == 0 && dot(cy2p, cy2p) <= cy.radius * cy.radius)
		return (cy.normal);
	d = sqrt(dot(subvec(p, cy.pos), subvec(p, cy.pos)) - cy.radius * cy.radius);
	if (dot(cy.normal, subvec(p, cy.pos)) < 0)
		cy.normal = invec(cy.normal);
	c0 = addvec(cy.pos, mulvec(d, cy.normal));
	v = normalize(subvec(p, c0));
	return (v);
}

int		intersect_circle(t_ray ray, t_cy cy, t_vec c, double *t)
{
	t_vec 	normal;
	double	dist;
	double	denom;
	t_vec	p;
	t_vec	cp;

	normal = get_normal(c, cy);
	denom = dot(ray.dir, normal);
	if (denom != 0)
	{
		dist = dot(subvec(c, ray.start), normal) / denom;
		if (dist < T_MIN)
			return (-1);
		p = addvec(ray.start, mulvec(dist, ray.dir));
		cp = subvec(p, c);
		if (dot(cp, cp) > cy.radius * cy.radius)
			return (-1);
		*t = dist;
		return (1);
	}
	return (-1);
}

int		intersect_caps(t_ray ray, t_cy cy, double *t)
{
	t_vec	p;
	double	dist;
	double	dot1;
	double	dot2;

	if (intersect_circle(ray, cy, cy.pos2, &dist) == 1 && dist < *t)
		*t = dist;
	if (intersect_circle(ray, cy, cy.pos, &dist) == 1 && dist < *t)
		*t = dist;
	p = addvec(ray.start, mulvec(*t, ray.dir));
	dot1 = dot(cy.normal, subvec(p, cy.pos));
	dot2 = dot(invec(cy.normal), subvec(p, cy.pos2));
	if (dot1 < 0 || dot2 < 0)
	{
		if (dot2 < 0 && intersect_circle(ray, cy, cy.pos2, &dist) == 1)
			*t = dist;
		else if (dot1 < 0 && intersect_circle(ray, cy, cy.pos, &dist) == 1)
			*t = dist;
		else
			return (-1);
	}
	return (1);
}

double	cylinder_intersect(t_ray ray, t_cy cy)
{
	double	t;
	t_vec	p0;

	p0 = subvec(ray.start, cy.pos);

	// t_vec v1 = mulvec(dot(ray.dir, cy.normal), cy.normal);
	// t_vec v2 = mulvec(dot(p0, cy.normal), cy.normal);
	// g_a = dot(subvec(ray.dir, v1), subvec(ray.dir, v1));
	// g_b = dot(subvec(ray.dir, v1), subvec(p0, v2));
	// g_c = dot(subvec(p0, v2), subvec(p0, v2)) - cy.radius * cy.radius;

	g_a = dot(ray.dir, ray.dir) - pow(dot(ray.dir, cy.normal), 2);
	g_b = dot(ray.dir, p0) - dot(ray.dir, cy.normal) * dot(p0, cy.normal);
	g_c = dot(p0, p0) - pow(dot(p0, cy.normal), 2) - cy.radius * cy.radius;

	g_disc = g_b * g_b - g_a * g_c;
	if (g_disc < 0)
		return (-1);
	g_t1 = (-g_b - sqrt(g_disc)) / g_a;
	g_t2 = (-g_b + sqrt(g_disc)) / g_a;
	if (g_t2 < T_MIN)
		return (-1);
	if (g_t1 > T_MIN)
		t = g_t1;
	else
		t = g_t2;
	if (intersect_caps(ray, cy, &t) == -1)
		return (-1);
	return (t);
}

void	closest_cy(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double 	t;
	t_cy cy;

	cy = *((t_cy *)data->curr_shape);
	t = cylinder_intersect(data->ray, cy);
	if (t != -1 && t < (data->t_min))
	{
		*col = ((t_cy *)data->curr_shape)->color;
		data->t_min = t;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = get_normal(*inter_pt, cy);
	}
}
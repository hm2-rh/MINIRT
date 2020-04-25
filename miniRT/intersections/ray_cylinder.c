#include "../minirt.h"

t_vec	g_c2;
double	g_a;
double	g_b;
double	g_c;
double	g_disc;
double	g_t1;
double	g_t2;
int		g_b1;
int		g_b2;

t_vec	get_normal(t_vec p, t_cy cy)
{
	t_vec c0;
	t_vec v;

	if (p.x < cy.pos.x + cy.radius && p.x > cy.pos.x - cy.radius &&
		p.z < cy.pos.z + cy.radius && p.z > cy.pos.z - cy.radius)
	{
		if (p.y < cy.pos.y + cy.height + T_MIN && p.y > cy.pos.y + cy.height - T_MIN)
			return ((t_vec){0,-1,0});
		if (p.y < cy.pos.y + T_MIN && p.y>cy.pos.y - T_MIN)
			return ((t_vec){0,1,0});
	}
	c0 = (t_vec){cy.pos.x, p.y, cy.pos.z};
	v = normalize(subvec(p, c0));
	return (v);
}

int		intersect_base(t_ray ray, t_cy cy, t_vec c, double *t)
{
	t_vec 	normal;
	t_vec 	p0;
	double	d;
	double	dist;
	t_vec	p;

	normal = get_normal(c, cy);
	p0 = subvec(ray.start, cy.pos);
	d = - (normal.x *(c.x - cy.pos.x) + normal.y * (c.y-cy.pos.y) + normal.z * (c.z - cy.pos.z));
	if (normal.x * ray.dir.x + normal.y * ray.dir.y + normal.z * ray.dir.z == 0)
		return (-1);
	dist = -(normal.x * p0.x + normal.y * p0.y + normal.z * p0.z + d)
			/ (normal.x * ray.dir.x + normal.y * ray.dir.y+ normal.z * ray.dir.z);
	if (dist < T_MIN)
		return (-1);
	p.x = p0.x+dist*ray.dir.x;
	p.y = p0.y+dist*ray.dir.y;
	p.z = p0.z+dist*ray.dir.z;
	if (p.x * p.x + p.z * p.z - cy.radius * cy.radius > T_MIN)
		return (-1);
	*t = dist;
	return (1);
}

double	cylinder_intersect(t_ray ray, t_cy cy)
{
	double	t;
	t_vec	p0;
	t_vec	p;
	double	y;
	double	dist;

	p0 = subvec(ray.start, cy.pos);
	g_c2 = (t_vec){cy.pos.x, cy.pos.y + cy.height, cy.pos.z};
	g_a = ray.dir.x * ray.dir.x + ray.dir.z* ray.dir.z;
	g_b = ray.dir.x * p0.x + ray.dir.z * p0.z;
	g_c = p0.x * p0.x + p0.z * p0.z - cy.radius * cy.radius;
	g_disc = g_b * g_b - g_a * g_c;
	if (g_disc < T_MIN)
		return (-1);
	g_t1 = (-g_b - sqrt(g_disc)) / g_a;
	g_t2 = (-g_b + sqrt(g_disc)) / g_a;
	if (g_t2 < T_MIN)
		return (-1);
	if (g_t1 > T_MIN)
		t = g_t1;
	else
		t = g_t2;
	y = p0.y+t*ray.dir.y;
	if (y > cy.height + T_MIN || y < -T_MIN)
	{
		g_b1 = intersect_base(ray, cy, g_c2, &dist);
		if (g_b1 == 1)
			t = dist;
		g_b2 = intersect_base(ray, cy, cy.pos, &dist);
		if (g_b2 == 1 && dist > T_MIN && dist <= t)
			t = dist;
	}
	p = addvec(ray.start, mulvec(t, ray.dir));
	if (p.y > cy.pos.y + cy.height + T_MIN || p.y < cy.pos.y - T_MIN)
		return (-1);
	return (t);
}

void	closest_cy(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double 	t;

	t = cylinder_intersect(data->ray, *((t_cy *)data->curr_shape));
	if (t != -1 && t < (data->t_min))
	{
		*col = ((t_cy *)data->curr_shape)->color;
		data->t_min = t;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = get_normal(*inter_pt, *((t_cy *)data->curr_shape));
	}
}
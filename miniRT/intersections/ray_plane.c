#include "../minirt.h"

double	plane_intersect(t_ray ray, t_plane pl)
{
	double denom;
	double t;

	t = -1;
	denom = dot(normalize(ray.dir), pl.normal);
	if (denom > T_MIN)
		t = dot(subvec(pl.ref, ray.start), pl.normal) / denom;
	return (t);
}

void	closest_pl(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	double t;

	t = plane_intersect(data->ray, *((t_plane *)data->curr_shape));
	if (t != -1 && t < data->t_min)
	{
		*col = ((t_plane *)data->curr_shape)->color;
		data->t_min = t;
		*inter_pt = addvec(data->ray.start, mulvec(t, data->ray.dir));
		*n = invec(((t_plane *)data->curr_shape)->normal);
	}
}

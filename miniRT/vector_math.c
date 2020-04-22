/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:10:31 by hrhirha           #+#    #+#             */
/*   Updated: 2020/03/11 16:09:20 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

double			dot(t_vec v1, t_vec v2)
{
	double dot;

	dot = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (dot);
}

t_vec			cross(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.y * v2.z - v2.y * v1.z,
					v2.x * v1.z - v1.x * v2.z,
					v1.x * v2.y - v2.x * v1.y});
}

t_vec			normalize(t_vec v)
{
	double	magnitude;

	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (magnitude == 0)
		magnitude = 1;
	return ((t_vec){v.x / magnitude, v.y / magnitude, v.z / magnitude});
}

t_vec			subvec(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vec			addvec(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vec			mulvec(double n, t_vec v)
{
	return ((t_vec){n * v.x, n * v.y, n * v.z});
}

t_vec			invec(t_vec vec)
{
	return ((t_vec){-vec.x, -vec.y, -vec.z});
}
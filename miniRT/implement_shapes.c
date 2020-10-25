/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_shapes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:53:41 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 10:07:55 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	implement_sp(char **tab, t_list **shapes)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	sp->id = SP;
	sp->center = ext_vec(tab[1]);
	sp->radius = ft_atolf(tab[2]) / 2.0;
	sp->color = ext_color_ratio(tab[3]);
	ft_lstadd_back(shapes, ft_lstnew(sp));
}

void	implement_pl(char **tab, t_list **shapes)
{
	t_plane *pl;

	pl = malloc(sizeof(t_plane));
	pl->id = PL;
	pl->ref = ext_vec(tab[1]);
	pl->normal = ext_vec(tab[2]);
	normal_error(pl->normal);
	pl->normal = normalize(pl->normal);
	pl->color = ext_color_ratio(tab[3]);
	ft_lstadd_back(shapes, ft_lstnew(pl));
}

void	implement_tr(char **tab, t_list **shapes)
{
	t_tr *tr;

	tr = malloc(sizeof(t_tr));
	tr->id = TR;
	tr->p0 = ext_vec(tab[1]);
	tr->p1 = ext_vec(tab[2]);
	tr->p2 = ext_vec(tab[3]);
	tr->p0p1 = subvec(tr->p1, tr->p0);
	tr->p0p2 = subvec(tr->p2, tr->p0);
	tr->color = ext_color_ratio(tab[4]);
	ft_lstadd_back(shapes, ft_lstnew(tr));
}

void	implement_cy(char **tab, t_list **shapes)
{
	t_cy *cy;

	cy = malloc(sizeof(t_cy));
	cy->id = CY;
	cy->pos = ext_vec(tab[1]);
	cy->normal = ext_vec(tab[2]);
	normal_error(cy->normal);
	cy->normal = normalize(cy->normal);
	cy->radius = ft_atolf(tab[3]) / 2.0;
	cy->height = ft_atolf(tab[4]);
	cy->color = ext_color_ratio(tab[5]);
	cy->pos2 = addvec(cy->pos, mulvec(cy->height, cy->normal));
	ft_lstadd_back(shapes, ft_lstnew(cy));
}

void	implement_sq(char **tab, t_list **shapes)
{
	t_sq	*sq;
	t_vec	up;

	up = (t_vec){0, -1, 0};
	sq = malloc(sizeof(t_sq));
	sq->id = SQ;
	sq->center = ext_vec(tab[1]);
	sq->normal = ext_vec(tab[2]);
	normal_error(sq->normal);
	sq->normal = normalize(sq->normal);
	if (sq->normal.z > 0)
		sq->normal = invec(sq->normal);
	if (vec_cmp(up, sq->normal) == 1 || vec_cmp(sq->normal, invec(up)) == 1)
		up = (t_vec){0, 0, 1};
	sq->u = cross(up, sq->normal);
	sq->v = cross(sq->normal, sq->u);
	sq->side = ft_atolf(tab[3]);
	sq->color = ext_color_ratio(tab[4]);
	ft_lstadd_back(shapes, ft_lstnew(sq));
}

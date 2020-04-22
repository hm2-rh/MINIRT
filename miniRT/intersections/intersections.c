/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:51:07 by hrhirha           #+#    #+#             */
/*   Updated: 2020/03/11 17:19:36 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	first_inter(t_data *data, t_vec *inter_pt, t_vec *n, t_vec *col)
{
	t_list	*tmp;

	data->t_min = T_MAX;
	tmp = data->shapes;
	while (tmp)
	{
		data->curr_shape = tmp->content;
		if (((t_sp *)data->curr_shape)->id == SP)
			closest_sp(data, inter_pt, n, col);
		if (((t_plane *)data->curr_shape)->id == PL)
			closest_pl(data, inter_pt, n, col);
		if (((t_tr *)data->curr_shape)->id == TR)
			closest_tr(data, inter_pt, n, col);
		if (((t_sq *)data->curr_shape)->id == SQ)
			;
		if (((t_cy *)data->curr_shape)->id == CY)
			;
		tmp = tmp->next;
	}
	if (data->t_min == T_MAX)
		return (-1);
	return (data->t_min);
}

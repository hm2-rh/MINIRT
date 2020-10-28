/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 14:32:33 by hrhirha           #+#    #+#             */
/*   Updated: 2020/10/25 14:32:35 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		mclose(void *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
}

int		keys(int key, t_data *data)
{
	if (key == ESC_KEY)
		mclose(data);
	if (key == SP_KEY)
	{
		data->imgs = data->imgs->next;
		data->curr_img = data->imgs->content;
		mlx_put_image_to_window(data->ptr, data->win,
								data->curr_img->img, 0, 0);
	}
	return (key);
}

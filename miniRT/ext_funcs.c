/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:53:15 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 10:05:40 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	ext_vec(char *s)
{
	char	**sub;
	t_vec	vec;
	int		i;

	i = 0;
	sub = ft_split(s, ',');
	if (tab_len(sub) != 3)
	{
		ft_putstr_fd("Error\nWrong VECTOR format\n", 0);
		free_tab(sub);
		exit(-1);
	}
	vec.x = ft_atolf(sub[0]);
	vec.y = ft_atolf(sub[1]);
	vec.z = ft_atolf(sub[2]);
	free_tab(sub);
	return (vec);
}

t_color	ext_color(char *s)
{
	char	**sub;
	t_color	color;
	int		i;

	i = 0;
	sub = ft_split(s, ',');
	if (tab_len(sub) != 3)
	{
		ft_putstr_fd("Error\nWrong COLOR format\n", 0);
		free_tab(sub);
		exit(-1);
	}
	color.r = ft_atoi(sub[0]);
	color.g = ft_atoi(sub[1]);
	color.b = ft_atoi(sub[2]);
	if (color.r < 0 || color.r > 255 ||
		color.g < 0 || color.g > 255 ||
		color.b < 0 || color.b > 255)
	{
		ft_putstr_fd("Error\nWrong RGB values\n", 0);
		exit(-1);
	}
	free_tab(sub);
	return (color);
}

t_vec	ext_color_ratio(char *s)
{
	char	**sub;
	t_vec	color;
	int		i;

	i = 0;
	sub = ft_split(s, ',');
	if (tab_len(sub) != 3)
	{
		ft_putstr_fd("Error\nWrong COLOR format\n", 0);
		free_tab(sub);
		exit(-1);
	}
	/*
	** check for doubles in RGB values
	*/
	color.x = ft_atoi(sub[0]) / 255.0;
	color.y = ft_atoi(sub[1]) / 255.0;
	color.z = ft_atoi(sub[2]) / 255.0;
	if (color.x * 255.0 < 0 || color.x * 255.0 > 255 ||
		color.y * 255.0 < 0 || color.y * 255.0 > 255 ||
		color.z * 255.0 < 0 || color.z * 255.0 > 255)
	{
		ft_putstr_fd("Error\nWrong RGB values\n", 0);
		exit(-1);
	}
	free_tab(sub);
	return (color);
}

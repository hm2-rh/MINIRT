/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:42:40 by hrhirha           #+#    #+#             */
/*   Updated: 2020/11/04 12:41:05 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	ratio_error(char **tab, int i)
{
	if (is_double(tab[i]) == -1)
	{
		ft_putstr_fd("Error\nWrong ratio value given to ", 1);
		ft_putstr_fd(tab[0], 0);
		ft_putstr_fd("\n", 0);
		free_and_exit(tab);
	}
}

void	normal_error(t_vec normal)
{
	if ((normal.x < -1 || normal.x > 1) ||
		(normal.y < -1 || normal.y > 1) ||
		(normal.z < -1 || normal.z > 1))
	{
		ft_putstr_fd("Error\nnormal vector not in range [-1, 1]\n", 1);
		exit(-1);
	}
}

void	double_error_msg(char **tab, int i)
{
	if (is_double(tab[i]) == -1)
	{
		ft_putstr_fd("Error\nWrong value at ", 1);
		ft_putstr_fd(tab[0], 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
		free_and_exit(tab);
	}
}

void	check_res_values(t_data *data, t_res *res, char **tab)
{
	int	wmax;
	int	hmax;

	if (res->w < 0 || res->h < 0)
	{
		ft_putstr_fd("Error\nNegative RES values\n", 1);
		free_and_exit(tab);
	}
	mlx_get_screen_size(data->ptr, &wmax, &hmax);
	if (res->w > wmax)
		res->w = wmax;
	if (res->h > hmax)
		res->h = hmax;
}

void	negative_fov(char **tab, double fov)
{
	if (fov < 0)
	{
		ft_putstr_fd("Error\nnegative FOV: ", 1);
		ft_putstr_fd(tab[3], 1);
		ft_putstr_fd("\n", 1);
		free_and_exit(tab);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:51:21 by hrhirha           #+#    #+#             */
/*   Updated: 2020/10/14 10:11:16 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_info_error(char *s)
{
	ft_putstr_fd("Error\nWrong number of informations given to ", 0);
	ft_putstr_fd(s, 0);
	ft_putstr_fd("\n", 0);
}

void	print_load_error(t_data *data)
{
	if (data->res.loaded == -1)
	{
		ft_putstr_fd("Error\nResolution not found..\n", 0);
		exit(-1);
	}
	if (data->amb.loaded == -1)
	{
		ft_putstr_fd("Error\nAmbient light not found..\n", 0);
		exit(-1);
	}
	if (!data->cams)
	{
		ft_putstr_fd("Error\nCouldn't find any cameras..\n", 0);
		exit(-1);
	}
}

int		check_errors(char **tab)
{
	if (tab_len(tab) != 4 && ((tab[0][0] == 's' && tab[0][1] == 'p') ||
							(tab[0][0] == 'p' && tab[0][1] == 'l')))
	{
		print_info_error(tab[0]);
		return (1);
	}
	if (tab_len(tab) != 5 && ((tab[0][0] == 't' && tab[0][1] == 'r') ||
							(tab[0][0] == 's' && tab[0][1] == 'q')))
	{
		print_info_error(tab[0]);
		return (1);
	}
	if (tab_len(tab) != 6 && (tab[0][0] == 'c' && tab[0][1] == 'y'))
	{
		print_info_error(tab[0]);
		return (1);
	}
	return (-1);
}

void	normal_error(t_vec normal)
{
	if ((normal.x < -1 || normal.x > 1) ||
		(normal.y < -1 || normal.y > 1) ||
		(normal.z < -1 || normal.z > 1))
	{
		ft_putstr_fd("Error\nnormal vector coordinates \
				should be between -1 and 1\n", 1);
		exit(-1);
	}
}

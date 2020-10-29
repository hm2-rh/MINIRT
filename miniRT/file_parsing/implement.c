/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:53:26 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:53:30 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	implement_res(char *line, t_res *res)
{
	char **tab;

	tab = ft_split(line, ' ');
	tab_len_error(tab, 3);
	if (is_int(tab[1]) == -1 || is_int(tab[2]) == -1)
	{
		ft_putstr_fd("Error\nWrong RES values\n", 1);
		free_and_exit(tab);
	}
	res->w = ft_atoi(tab[1]);
	res->h = ft_atoi(tab[2]);
	check_res_values(res, tab);
	res->loaded++;
	if (res->loaded > 0)
	{
		ft_putstr_fd("Error\nmultiple resolutions..\n", 1);
		free_and_exit(tab);
	}
	free_tab(tab);
}

void	implement_amb(char *line, t_amb *amb)
{
	char **tab;

	tab = ft_split(line, ' ');
	tab_len_error(tab, 3);
	ratio_error(tab, 1);
	amb->ratio = ft_atolf(tab[1]);
	if (amb->ratio < 0 || amb->ratio > 1)
	{
		ft_putstr_fd("Error\nambient ratio not in range [0.0, 1.0]..\n", 1);
		free_and_exit(tab);
	}
	amb->color = ext_color(tab[2]);
	amb->loaded++;
	if (amb->loaded > 0)
	{
		ft_putstr_fd("Error\nmultiple ambient lights..\n", 1);
		free_and_exit(tab);
	}
	free_tab(tab);
}

void	implement_lights(char *line, t_list **lights)
{
	char	**tab;
	t_light	*light;

	light = malloc(sizeof(t_light));
	tab = ft_split(line, ' ');
	tab_len_error(tab, 4);
	light->pos = ext_vec(tab[1]);
	ratio_error(tab, 2);
	light->ratio = ft_atolf(tab[2]);
	if (light->ratio < 0 || light->ratio > 1)
	{
		ft_putstr_fd("Error\nlight ratio not in range [0.0, 1.0]..\n", 1);
		free_and_exit(tab);
	}
	light->color = ext_color(tab[3]);
	ft_lstadd_back(lights, ft_lstnew(light));
	free_tab(tab);
}

void	implement_cameras(char *line, t_list **cams)
{
	char	**tab;
	t_cam	*cam;
	t_vec	down_guide;

	cam = malloc(sizeof(t_cam));
	tab = ft_split(line, ' ');
	tab_len_error(tab, 4);
	down_guide = (t_vec){0, 1, 0};
	cam->pos = ext_vec(tab[1]);
	cam->dir = ext_vec(tab[2]);
	normal_error(cam->dir);
	cam->dir = normalize(cam->dir);
	double_error_msg(tab, 3);
	cam->fov = ft_atolf(tab[3]);
	negative_fov(tab, cam->fov);
	if (vec_cmp(cam->dir, down_guide) == 1 ||
		vec_cmp(cam->dir, invec(down_guide)) == 1)
		down_guide = (t_vec){0, 0, 1};
	cam->right = cross(down_guide, cam->dir);
	cam->up = cross(cam->right, cam->dir);
	ft_lstadd_back(cams, ft_lstnew(cam));
	free_tab(tab);
}

void	implement_shapes(char *line, t_list **shapes)
{
	char **tab;

	tab = ft_split(line, ' ');
	if (check_errors(tab) == 1)
		free_and_exit(tab);
	if (line[0] == 's' && line[1] == 'p')
		implement_sp(tab, shapes);
	if (line[0] == 'p' && line[1] == 'l')
		implement_pl(tab, shapes);
	if (line[0] == 't' && line[1] == 'r')
		implement_tr(tab, shapes);
	if (line[0] == 'c' && line[1] == 'y')
		implement_cy(tab, shapes);
	if (line[0] == 's' && line[1] == 'q')
		implement_sq(tab, shapes);
	free_tab(tab);
}

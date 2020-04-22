#include "minirt.h"

void	implement_res(char *line, t_res *res)
{
	char **tab;

	tab = ft_split(line, ' ');
	if (tab_len(tab) != 3)
	{
		print_info_error(tab[0]);
		free_tab(tab);
		exit(-1);
	}
	res->w = ft_atoi(tab[1]);
	res->h = ft_atoi(tab[2]);
	res->loaded++;
	if (res->loaded > 0)
	{
		ft_putstr_fd("Error\nmultiple resolutions..\n", 0);
		exit(-1);
	}
	free_tab(tab);
}

void	implement_amb(char *line, t_amb *amb)
{
	char **tab;

	tab = ft_split(line, ' ');
	if (tab_len(tab) != 3)
	{
		print_info_error(tab[0]);
		free_tab(tab);
		exit(-1);
	}
	amb->ratio = ft_atolf(tab[1]);
	if (amb->ratio > 1 || amb->ratio < 0)
	{
		ft_putstr_fd("Error\nRatio should be between 0 and 1..\n", 0);
		exit(-1);
	}
	amb->color = ext_color(tab[2]);
	amb->loaded++;
	if (amb->loaded > 0)
	{
		ft_putstr_fd("Error\nmultiple ambient lights..\n", 0);
		exit(-1);
	}
	free_tab(tab);
}

void	implement_lights(char *line, t_list **lights)
{
	char	**tab;
	t_light	*light;

	light = malloc(sizeof(t_light));
	tab = ft_split(line, ' ');
	if (tab_len(tab) != 4)
	{
		print_info_error(tab[0]);
		free_tab(tab);
		exit(-1);
	}
	light->pos = ext_vec(tab[1]);
	light->ratio = ft_atolf(tab[2]);
	if (light->ratio > 1 || light->ratio < 0)
	{
		ft_putstr_fd("Error\nRatio should be between 0 and 1..\n", 0);
		exit(-1);
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
	if (tab_len(tab) != 4)
	{
		print_info_error(tab[0]);
		free_tab(tab);
		exit(-1);
	}
	down_guide = (t_vec){0, 1, 0};
	cam->pos = ext_vec(tab[1]);
	cam->dir = ext_vec(tab[2]);
	cam->fov = ft_atolf(tab[3]);
	cam->right = cross(down_guide, cam->dir);
	cam->down = cross(cam->dir, cam->right);
	ft_lstadd_back(cams, ft_lstnew(cam));
	free_tab(tab);
}

void	implement_shapes(char *line, t_list **shapes)
{
	char **tab;

	tab = ft_split(line, ' ');
	if (check_errors(tab) == 1)
	{
		free_tab(tab);
		exit(-1);
	}
	if (line[0] == 's' && line[1] == 'p')
		implement_sp(tab, shapes);
	if (line[0] == 'p' && line[1] == 'l')
		implement_pl(tab, shapes);
	if (line[0] == 't' && line[1] == 'r')
		implement_tr(tab, shapes);
	if (line[0] == 'c' && line[1] == 'y')
		;
	if (line[0] == 's' && line[1] == 'q')
		;
	free_tab(tab);
}

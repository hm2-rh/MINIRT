/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 07:50:14 by hrhirha           #+#    #+#             */
/*   Updated: 2020/03/11 17:19:32 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		keys(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == 65307)
		exit(1);
	if (key == 99)
	{
		data->cams = data->cams->next;
		data->curr_cam = data->cams->content;
		ray_trace(data);
		mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
	}
	return (key);
}

void	cams_circle(t_list **cams)
{
	t_list *last;

	last = *cams;
	while (last)
	{
		if (last->next == NULL)
		{
			last->next = *cams;
			break ;
		}
		last = last->next;
	}
}

void	start(t_data *data)
{
	cams_circle(&data->cams);
	data->ptr = mlx_init();
	data->win = mlx_new_window(data->ptr, data->res.w, data->res.h, "my very first RayTracer");
	data->img = mlx_new_image(data->ptr, data->res.w, data->res.h);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len, &data->endian);
	ray_trace(data);
	if (data->save == 1)
	{
		save_image(data, 0, 0);
		exit(-1);
	}
}

int	open_file(char *s)
{
	int fd;
	
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFile not found..\n", 0);
		return (-1);
	}
	if (ft_strncmp(&s[ft_strlen(s) - 3], ".rt", 4) != 0)
	{
		ft_putstr_fd("Error\nInvalid format..\n", 0);
		close(fd);
		return (-1);
	}
	return (fd);
}

int		main(int ac, char **av)
{
	t_data	data;
	int		fd;

	if (ac == 3 && ft_strncmp(av[2], "--save", 7) == 0)
		data.save = 1;
	if (ac > 1 && ac <= 3)
	{
		fd = open_file(av[1]);
		if (fd == -1)
			return (-1);
		read_fd(fd, &data);
		close(fd);
		print_load_error(&data);
		start(&data);
		mlx_put_image_to_window(data.ptr, data.win, data.img, 0, 0);
		mlx_key_hook(data.win, keys, &data);
		mlx_loop(data.ptr);
		return (0);
	}
	ft_putstr_fd("Error\nUsage: ./minirt file_name.rt\n", 0);
	return (-1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhirha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 09:50:42 by hrhirha           #+#    #+#             */
/*   Updated: 2020/04/23 09:50:47 by hrhirha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start(t_data *data)
{
	data->ptr = mlx_init();
	data->imgs = NULL;
	data->curr_img = NULL;
	render_scenes(data);
	data->curr_img = (t_img *)(data->imgs->content);
	// if (data->save == 1)
	// {
	// 	save_image(data, 0, 0);
	// 	exit(EXIT_SUCCESS);
	// }
	lst_circle(&data->imgs);
	data->win = mlx_new_window(data->ptr, data->res.w, data->res.h,
								"RayTracer");
}

int		open_file(char *s)
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
		data.bmp_name = av[1];
		start(&data);
		mlx_put_image_to_window(data.ptr, data.win, data.curr_img->img, 0, 0);
		mlx_key_hook(data.win, keys, &data);
		mlx_loop(data.ptr);
		return (0);
	}
	ft_putstr_fd("Error\nUsage: ./minirt file_name.rt\n", 0);
	return (-1);
}

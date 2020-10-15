#include "minirt.h"

int		main()
{
	t_data 	data;
	t_list	*tmp;
	void	*obj;
	int		fd;

	fd = open("scene.rt", O_RDONLY);
	read_fd(fd, &data);
	printf("RES = (%d, %d)\tamb.ratio = %lf\n", data.res.w, data.res.h, data.amb.ratio);
	tmp = data.shapes;
	while (tmp)
	{
		obj = tmp->content;
		if (((t_sp *)obj)->id == SP)
			printf("sp: (%lf, %lf, %lf)\n", ((t_sp *)obj)->color.x, ((t_sp *)obj)->color.y, ((t_sp *)obj)->color.z);
		if (((t_plane *)obj)->id == PL)
			printf("pl: (%lf, %lf, %lf)\n", ((t_plane *)obj)->color.x, ((t_plane *)obj)->color.y, ((t_plane *)obj)->color.z);
		if (((t_tr *)obj)->id == TR)
			printf("tr: (%lf, %lf, %lf)\n", ((t_tr *)obj)->color.x, ((t_tr *)obj)->color.y, ((t_tr *)obj)->color.z);
		tmp = tmp->next;
	}
	printf("cameras\n");
	tmp = data.cams;
	while (tmp)
	{
		data.curr_cam = tmp->content;
		printf("cam_pos = (%lf, %lf, %lf)\n", data.curr_cam->pos.x, data.curr_cam->pos.y, data.curr_cam->pos.z);
		tmp = tmp->next;
	}

	
	while (data.shapes)
	{
		tmp = data.shapes;
		data.shapes = data.shapes->next;
		free(tmp->content);
		free(tmp);
	}
	while (data.lights)
	{
		tmp = data.lights;
		data.lights = data.lights->next;
		free(tmp->content);
		free(tmp);
	}
	while (data.cams)
	{
		tmp = data.cams;
		data.cams = data.cams->next;
		free(tmp->content);
		free(tmp);
	}
}

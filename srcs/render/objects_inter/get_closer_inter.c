//
// Created by jules on 12/06/2024.
//

#include <miniRT_render.h>

void	closer_obj(t_line *line, void **obj, t_inter_point (*f) (t_line*, void*), t_inter_point	*closer)
{
	t_inter_point	competidor;
	int 			i;

	i = 0;
	while (obj[i])
	{
		competidor = f(line, obj[i]);
		if (competidor.object)
		{
			if (!closer->object)
				*closer = competidor;
			if (point_distance(line->origin, competidor.coordinates)
				< point_distance(line->origin, closer->coordinates))
				*closer = competidor;
		}
		i++;
	}
}

t_inter_point	get_closer_inter(t_line *line, t_scene *scene)
{
	t_inter_point	closer;

	closer.object = NULL;
	closer_obj(line, (void **) scene->sphere,
		(t_inter_point (*)(t_line*, void*)) &sphere_inter, &closer);
	closer_obj(line, (void **) scene->plane,
		(t_inter_point (*)(t_line*, void*)) &plane_inter, &closer);
	closer_obj(line, (void **) scene->cylinder,
		(t_inter_point (*)(t_line*, void*)) &cylinder_inter, &closer);
	return (closer);
}

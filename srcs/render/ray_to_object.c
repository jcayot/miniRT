//
// Created by jules on 11/06/2024.
//

#include <miniRT_render.h>

t_vector	ray_direction(t_camera *cam, t_image_size s, t_pixel_cdts p)
{
	t_vector		ray_vector;
	t_coordinates	projection_point;
	float			focal_len;
	t_vector		v_up;
	t_vector		v_right;

	focal_len = s.W/(2 * tanf(cam->fov / 2));
	projection_point.x = ((2.0f * (p.x + 0.5f) / s.W) - 1.0f) * (s.W / (2.0f * focal_len));
	projection_point.y = (1.0f - (2.0f * (p.y + 0.5f) / s.H)) * (s.H / (2.0f * focal_len));
	v_up = orthogonal_vector(cam->vector, 1, 1);
	v_right = cross_product(cam->vector, v_up);
	ray_vector = add_vector(scalar_vector(projection_point.x, v_right),
							scalar_vector(projection_point.y, v_up));
	ray_vector = add_vector(ray_vector, scalar_vector(focal_len, cam->vector));
	ray_vector = normalize_vector(ray_vector);
	return (ray_vector);
}

t_ray	ray_to_object(t_scene* scene, t_image_size s, t_pixel_cdts p)
{
	t_ray	ray;

	ray.line.origin = scene->camera->center;
	ray.line.direction = ray_direction(scene->camera, s, p);
	printf("Ray direction: X = %f, Y = %f, Z = %f\n", ray.line.direction.x, ray.line.direction.y, ray.line.direction.z);
	ray.inter_point = get_closer_inter(&ray.line, scene);
	return (ray);
}

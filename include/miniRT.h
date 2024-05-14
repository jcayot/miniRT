//
// Created by Jules Cayot on 13/05/2024.
//

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/fcntl.h>
# include <ft_maths.h>
# include <MLX42/MLX42.h>
# include <libft.h>
# include <ft_utils.h>

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}	t_rgb;

typedef struct	s_ambient_light
{
	float	ratio;
	t_rgb	rbg;
}	t_ambient_light;

typedef struct	s_camera
{
	t_coordinates		view_point;
	t_vector			vector;
	int 				fov;
}	t_camera;

typedef struct	s_light
{
	t_coordinates	light_point;
	float 			brightness;
}	t_light;

typedef struct	s_sphere
{
	t_coordinates	light_point;
	float			brightness;
	t_rgb			rgb;
}	t_sphere;

typedef struct	s_plane
{
	t_coordinates	coordinates;
	t_vector		vector;
	t_rgb			rgb;
}	t_plane;

typedef struct	s_cylinder
{
	t_coordinates	coordinates;
	t_vector		vector;
	float			diameter;
	float			height;
	t_rgb			rgb;
}	t_cylinder;

typedef struct	s_render_scene
{
	t_ambient_light	**ambient_light;
	t_camera		**camera;
	t_sphere		**sphere;
	t_plane			**plane;
	t_cylinder 		**cylinder;
}	 t_render_scene;

t_render_scene	parse_file(char *filename);

#endif //MINIRT_H
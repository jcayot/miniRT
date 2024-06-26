//
// Created by Jules Cayot on 13/05/2024.
//

#include <miniRT.h>

void	close_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	miniRT(char *filename)
{
	mlx_t			*mlx;
	t_scene			scene;
	int 			result;

	scene = parse_file(filename);
	if (!scene.ambient_light)
		return (1);
	result = 1;
	print_all(&scene);
	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (mlx)
	{
		mlx_loop_hook(mlx, &close_hook, mlx);
		result = render_scene(mlx, &scene);
		mlx_terminate(mlx);
	}
	else
		ft_putmlx_error();
	free_render_scene(&scene);
	return (result);
}

//int main() {
//	t_line ray = {{0, 0, 0}, {1, 1, 1}};
//	t_sphere sphere = {{5, 5, 5}, 2, {255,255,255}};
//	t_inter_point inter = sphere_inter(&ray, &sphere);
//
//	printf("Intersection at: (%f, %f, %f)\n", inter.coordinates.x, inter.coordinates.y, inter.coordinates.z);
//
//	return 0;
//}

int	main(int n, char *args[])
{
	if (n != 2)
		return (1);
	return (miniRT(args[1]));
}

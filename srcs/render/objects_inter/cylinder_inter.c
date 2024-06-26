//
// Created by jules on 11/06/2024.
//

#include <miniRT_render.h>

t_inter_point	cyka_circles_inter(t_line *line, t_cylinder *cylinder)
{
	t_inter_point	inter1;
	t_inter_point	inter2;
	t_plane			circles[2];

	get_cyka_circles_planes(cylinder, circles);
	inter1 = plane_inter(line, &circles[0]);
	inter2 = plane_inter(line, &circles[1]);
	inter1.object = cylinder;
	inter1.object_type = cyka_circle;
	inter2.object = cylinder;
	inter2.object_type = cyka_circle;
	if (point_distance(inter1.coordinates, circles[0].coordinates) < cylinder->diameter
		&& point_distance(inter1.coordinates, line->origin)
		< point_distance(inter2.coordinates, line->origin))
		return (inter1);
	if (point_distance(inter2.coordinates, circles[1].coordinates) < cylinder->diameter
		&& point_distance(inter2.coordinates, line->origin)
		   < point_distance(inter1.coordinates, line->origin))
		return (inter2);
	inter1.object = NULL;
	return (inter1);
}

float	curve_line_len(t_line *line, t_cylinder *cylinder)
{
	t_polyroot		roots;
	t_vector		A;
	t_vector		B;

	A = substract_vector(line->direction,scalar_vector(
			dot_product(line->direction, cylinder->vector), cylinder->vector));
	B = substract_vector(vector_from_points(line->origin, cylinder->center),
						 scalar_vector(dot_product(
								 vector_from_points(line->origin, cylinder->center),
								 cylinder->vector), cylinder->vector));
	roots = poly_root(dot_product(A, A), 2.0f * dot_product(A, B), dot_product(B, B) - powf(cylinder->diameter, 2.0f));
	if (roots.n == 0)
		return (-1.0f);
	else if (roots.n == 1)
		return (roots.values[0]);
	else
	{
		if (roots.values[0] > roots.values[1])
			return (roots.values[1]);
		else
			return (roots.values[0]);
	}
}

t_inter_point	cyka_curve_inter(t_line *line, t_cylinder *cylinder)
{
	t_inter_point	inter;
	float			line_len;

	inter.object = NULL;
	line_len = curve_line_len(line, cylinder);
	if (line_len == -1.0f)
		return (inter);
	inter.object_type = cyka;
	inter.object = cylinder;
	inter.coordinates = translate_point(line->origin, scalar_vector(line_len, line->direction));
	if (point_distance(cylinder->center, inter.coordinates) >
			sqrtf(powf(cylinder->height, 2.0f) + powf(cylinder->diameter, 2.0f)))
		inter.object = NULL;
	return (inter);
}

t_inter_point	cylinder_inter(t_line *line, t_cylinder *cylinder)
{
	t_inter_point	inter_cyka_part;
	t_inter_point	inter_circle_part;

	inter_cyka_part = cyka_curve_inter(line, cylinder);
	inter_circle_part = cyka_circles_inter(line, cylinder);
	if (inter_cyka_part.object && !inter_circle_part.object)
		return (inter_cyka_part);
	if (inter_circle_part.object && !inter_cyka_part.object)
		return (inter_circle_part);
	return (inter_cyka_part);
}

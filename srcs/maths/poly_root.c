/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayot <jcayot.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:07:25 by jcayot            #+#    #+#             */
/*   Updated: 2024/07/18 20:07:26 by jcayot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_maths.h>

t_polyroot	poly_root(float a, float b, float c)
{
	t_polyroot	roots;
	float		discriminant;

	roots.values[0] = 0;
	roots.values[1] = 0;
	discriminant = b * b - (4.0f * a * c);
	if (discriminant < 0.0f || isnanf(discriminant))
		roots.n = 0;
	else if (discriminant == 0.0f)
	{
		roots.n = 1;
		roots.values[0] = -b / (2.0f * a);
	}
	else
	{
		roots.n = 2;
		roots.values[0] = (-b + sqrtf(discriminant)) / (2.0f * a);
		roots.values[1] = (-b - sqrtf(discriminant)) / (2.0f * a);
	}
	return (roots);
}

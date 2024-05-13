/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayot <jcayot@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:15:43 by jcayot            #+#    #+#             */
/*   Updated: 2024/01/30 15:21:50 by jcayot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_intlen(int n)
{
	unsigned int	l;

	l = 1;
	if (n < 0)
		l++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		l++;
	}
	return (l);
}

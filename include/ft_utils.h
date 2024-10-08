/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayot <jcayot.student@hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:21:33 by jcayot            #+#    #+#             */
/*   Updated: 2024/07/11 18:21:35 by jcayot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <libft.h>
# include <pthread.h>
# include <sys/time.h>

char	*ft_strappend(char *s1, char *s2, int size);
void	*ft_free_array(void **array);
u_long	get_mst(void);
void	wait_threads(int n, pthread_t *threads);

#endif //FT_UTILS_H

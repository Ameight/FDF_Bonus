/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:10:46 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/12 04:47:57 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*get_point(int x, int y, char *str)
{
	t_point *tmp;

	if (!(tmp = ft_memalloc(sizeof(t_point))))
		return (NULL);
	tmp->x = (float)x;
	tmp->y = (float)y;
	tmp->z = (float)ft_atoi(str);
	tmp->color = BURLYWOOD;
	return (tmp);
}

t_map		*get_map(int width, int height)
{
	t_map	*tmp;

	if(!(tmp = ft_memalloc(sizeof(t_map))))
		return (NULL);
	if(!(tmp->points = ft_memalloc(sizeof(t_point *) * width * height)))
	{
		ft_memdel((void **)&tmp);
		return (NULL);
	}
	tmp->width = width;
	tmp->height = height;
	tmp->depth_min = 0;
	tmp->depth_max = 0;
	return (tmp);
}

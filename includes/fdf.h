/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 05:21:09 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/12 03:20:14 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "colors_keybords.h"

/*
** ********************
** ****** struct ******
** ********************
*/

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}					t_point;

typedef struct		s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_point		**points;
}					t_map;

/*
** ********************
** * Reading function *
** ********************
*/




/*
** ******************
** * Bonus function *
** ******************
*/


#endif

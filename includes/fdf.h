/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 05:21:09 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/12 05:05:54 by ejuana           ###   ########.fr       */
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

int			read_file(int fd, t_map **map);

static int	populate_map(t_map **map, t_list *list);

static int	get_lines(int fd, t_list **lst);

static int	clean_lst(t_list **lst, t_map **map);

t_map		*get_map(int width, int height);

t_point		*get_point(int x, int y, char *str);



/*
** ******************
** * Bonus function *
** ******************
*/


#endif

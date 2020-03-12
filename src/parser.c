/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 05:20:28 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/12 03:55:23 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** clean list structure && map ** 
*/

static int	clean_lst(t_list **lst, t_map **map)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->points);
		ft_memdel((void **)map);
	}
	return (0);
}

/*
** 
**lstrev
**
*/

static int	get_lines(int fd, t_list **lst)
{
	t_list	*temp;
	int		symbols_line;
	char	*line;
	int		reading;

	symbols_line = -1;
	while ((reading = get_next_line(fd, &line)))
	{
		if (symbols_line == -1)
			symbols_line = ft_word_counter(line, ' ');
		if(!(temp = ft_lstnew(line, ft_strlen(line) + 1)))
			return (clean_lst(lst, NULL));
		ft_lstadd(lst, temp);
		if (symbols_line != ft_word_counter(line, ' '))
			return (clean_lst(lst, NULL));
		ft_strdel(&line);
	}
	if (symbols_line == -1 || reading == -1)
		return (clean_lst(lst, NULL));
	ft_lstrev(lst);
	return (1);
}

void		find_depth(t_map *m)
{
	int			min;
	int			max;
	t_point		v;
	t_point		cur;

	min = INT_MAX;
	max = INT_MIN;
	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = *m->points[(int)v.y * m->width + (int)v.x];
			if (cur.z < min)
				min = cur.z;
			if (cur.z > max)
				max = cur.z;
			v.x++;
		}
		v.y++;
	}
	m->depth_min = min;
	m->depth_max = max;
}

static int	populate_map(t_map **m, t_list *list)
{
	t_list	*lst;
	char	**arr_dots;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < (*m)->height)
	{
		x = 0;
		if (!(arr_dots = ft_strsplit(lst->content, ' ')))
			return (clean_lst(&list, m));
		while (x < (*m)->width)
		{
			(*m)->points[y * (*m)->width + x] = get_vector(x, y, arr_dots[x]);
			x++;
		}
		ft_clen_split(&arr_dots);
		lst = lst->next;
		y++;
	}
	find_depth(*m);
	fill_colors(*m);
	clean_lst(&list, NULL);
	return (1);
}

int			read_file(int fd, t_map **m)
{
	t_list	*lst;

	lst = NULL;
	if (!(get_lines(fd, &lst)))
		return (0);
	*m = get_map(ft_countwords(lst->content, ' '), ft_lstcount(lst));
	if (*m == NULL)
		return (clean_lst(&lst, m));
	return (populate_map(m, lst));
}
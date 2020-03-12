/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 05:20:28 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/12 05:12:29 by ejuana           ###   ########.fr       */
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
/*
void		find_depth(t_map *map)
{
	int			min;
	int			max;
	t_point		v;
	t_point		cur;

	min = INT_MAX;
	max = INT_MIN;
	v.y = 0;
	while (v.y < map->height)
	{
		v.x = 0;
		while (v.x < map->width)
		{
			cur = *map->points[(int)v.y * map->width + (int)v.x];
			if (cur.z < min)
				min = cur.z;
			if (cur.z > max)
				max = cur.z;
			v.x++;
		}
		v.y++;
	}
	map->depth_min = min;
	map->depth_max = max;
}
*/
static int	populate_map(t_map **map, t_list *list)
{
	t_list	*lst;
	char	**arr_dots;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < (*map)->height)
	{
		x = 0;
		if (!(arr_dots = ft_strsplit(lst->content, ' ')))
			return (clean_lst(&list, map));
		while (x < (*map)->width)
		{
			(*map)->points[y * (*map)->width + x] = get_point(x, y, arr_dots[x]);
			x++;
		}
		ft_clean_split(&arr_dots);
		lst = lst->next;
		y++;
	}
	//find_depth(*map);
	//fill_colors(*map);
	clean_lst(&list, NULL);
	/*
	#include "stdio.h"
	int i;
	int j;

	i = 0;
	while(i < (*map)->height)
	{
		j = 0;
		while(j < (*map)->width)
		{
			printf("%d",(*map)->points[j]);
			j++;
		}
	}
	*/
	return (1);
}

int			read_file(int fd, t_map **map)
{
	t_list	*lst;

	lst = NULL;
	if (!(get_lines(fd, &lst)))
		return (0);
	*map = get_map(ft_word_counter(lst->content, ' '), ft_lstcount(lst));
	if (*map == NULL)
		return (clean_lst(&lst, map));
	return (populate_map(map, lst));
}
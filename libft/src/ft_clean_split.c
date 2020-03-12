/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 03:49:42 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/12 03:55:19 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_splitdel(char ***arr)
{
	char	**str;
	int		i;

	i = 0;
	str = *arr;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*arr)[i];
	}
	ft_memdel((void **)arr);
	return (0);
}

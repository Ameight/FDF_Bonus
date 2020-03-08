/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejuana <ejuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 22:15:36 by ejuana            #+#    #+#             */
/*   Updated: 2020/03/07 22:15:49 by ejuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_counter(char const *s, char c)
{
	int		count;
	char	*tmp;

	tmp = (char *)s;
	count = 0;
	while (*tmp)
	{
		while (*tmp && *tmp == c)
			tmp++;
		if (*tmp)
			count++;
		while (*tmp && *tmp != c)
			tmp++;
	}
	return (count);
}

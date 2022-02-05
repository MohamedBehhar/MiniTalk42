/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:23:56 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/04 12:03:16 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;
	size_t	k;

	b = (char *)big;
	l = (char *)little;
	i = 0;
	if (l[0] == '\0' )
		return (b);
	while (b[i] && i < len)
	{
		j = 0;
		k = i;
		while (b[k] == l[j] && k < len)
		{
			j++;
			if (l[j] == 0)
				return (&b[i]);
			k++;
		}
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:12:32 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/07 16:58:54 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c_set;
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char *)b;
	c_set = (unsigned char)c;
	if (!b)
		return (NULL);
	while (i < len)
	{
		d[i] = c_set;
		i++;
	}
	return (d);
}

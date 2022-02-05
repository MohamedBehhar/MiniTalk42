/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:21:04 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/04 20:25:49 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*src;
	unsigned char	ch;
	int				i;

	src = (char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (src[i])
	{
		if (src[i] == ch)
			break ;
		i++;
	}
	if (src[i] == ch)
		return (&src[i]);
	return (NULL);
}

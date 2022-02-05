/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:32:30 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/04 20:30:11 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*src;
	unsigned char	ch;
	int				len;

	src = (char *)s;
	ch = (unsigned char)c;
	len = ft_strlen(s);
	if (src[0] == '\0')
		return (NULL);
	if (src[len] == ch)
		return (&src[len]);
	while (len--)
	{
		if (src[len] == ch)
			return (&src[len]);
	}
	return (NULL);
}

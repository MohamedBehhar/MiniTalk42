/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:10:21 by mbehhar           #+#    #+#             */
/*   Updated: 2021/12/20 11:38:25 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((long int)len < 0)
		return (NULL);
	if (len > s_len)
		len = s_len;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (start < s_len)
	{
		while (i < len && s[start])
		{
			dest[i] = s[start];
			i++;
			start++;
		}
	}
	dest[i] = 0;
	return (dest);
}

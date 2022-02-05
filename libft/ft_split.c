/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:25:08 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/07 17:05:18 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	d_len(char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	s_len;

	i = 0;
	len = 0;
	s_len = ft_strlen(s);
	while (s[i] && i < s_len)
	{
		if (s[i] != c)
		{
			i++;
			len++;
		}
		while (s[i] != c && s[i])
			i++;
		i++;
	}
	return (len);
}

static char	**ft_free_dest(char **dest, int n)
{
	while (n--)
		free(dest[n]);
	free(dest);
	return (NULL);
}

static char	**ft_return_dst(char **dest, int i)
{
	dest[i] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;
	size_t	j;
	int		start;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * d_len(s, c) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j] && i < d_len(s, c))
	{
		while (s[j] == c)
			j++;
		start = j;
		while (s[j] != c && s[j])
			j++;
		dest[i] = ft_substr(s, start, (j - start));
		if (dest[i] == NULL)
			return (ft_free_dest(dest, i + 1));
		i++;
	}
	return (ft_return_dst(dest, i));
}

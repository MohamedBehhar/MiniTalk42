/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:18:00 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/04 20:31:15 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_there(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	d_len;

	len = ft_strlen(s1) - 1;
	start = 0;
	while (is_there(set, s1[start]))
		start++;
	if (start == len + 1)
		return (ft_strdup(""));
	while (is_there(set, s1[len]))
		len--;
	d_len = len - start + 1;
	return (ft_substr(s1, start, d_len));
}

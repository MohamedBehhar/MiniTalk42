/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:16:11 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/03 14:54:46 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	char	*ft_iszero(void)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * 2);
	if (!dest)
		return (NULL);
	dest[0] = '0';
	dest[1] = 0;
	return (dest);
}

char	*ft_itoa(int n)
{
	char		*dest;
	int			len;
	long int	nb;

	nb = n;
	if (nb == 0)
		return (ft_iszero());
	len = ft_numlen(nb);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	dest[len] = 0;
	if (nb < 0)
	{
		nb *= -1;
		dest[0] = '-';
	}
	while (nb != 0 && dest[len] != '-')
	{
		len--;
		dest[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:30:25 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/02 16:31:02 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}

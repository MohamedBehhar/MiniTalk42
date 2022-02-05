/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:41:59 by mbehhar           #+#    #+#             */
/*   Updated: 2021/11/04 20:18:35 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;
	t_list	*head;

	head = *lst;
	while (head != NULL)
	{
		next_node = head->next;
		del(head->content);
		free(head);
		head = next_node;
	}
	*lst = NULL;
}

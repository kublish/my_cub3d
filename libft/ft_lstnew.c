/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:34:08 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/24 15:50:00 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *elem;

	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(elem->content = (void *)malloc(content_size)))
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	else
	{
		elem->content = 0;
		elem->content_size = 0;
	}
	elem->next = NULL;
	return (elem);
}

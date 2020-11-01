/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:04:33 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/24 15:50:42 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *mpdelem;

	if (lst)
	{
		mpdelem = f(lst);
		mpdelem->next = ft_lstmap(lst->next, f);
		return (mpdelem);
	}
	return (NULL);
}

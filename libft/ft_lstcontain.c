/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:00:30 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/26 10:44:21 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns 1 if the lst contains an element with 'cntnt'
*/

#include "libft.h"

int	ft_lstcontain(t_list *lst, void *cntnt, int cntnt_size)
{
	if (lst && cntnt && cntnt_size)
	{
		if (memcmp(cntnt, lst->content, cntnt_size))
			return (ft_lstcontain(lst->next, cntnt, cntnt_size));
		else
			return (1);
	}
	return (0);
}

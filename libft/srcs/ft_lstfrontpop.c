/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfrontpop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:38:12 by zkubli            #+#    #+#             */
/*   Updated: 2020/02/10 08:13:45 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	*ft_lstfrontpop(t_list **lista)
{
	t_list	*tmp;
	void	*tmp_content;

	if (lista && *lista)
	{
		tmp = *lista;
		(*lista) = (*lista)->next;
		tmp_content = tmp->content;
		free(tmp);
		return (tmp_content);
	}
	else
		return (NULL);
}

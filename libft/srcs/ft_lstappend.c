/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:18:36 by zkubli            #+#    #+#             */
/*   Updated: 2020/01/28 07:50:01 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstappend(t_list **lista, t_list *listb)
{
	if (lista == NULL || listb == NULL)
		return ;
	else if ((*lista) == NULL)
		*lista = listb;
	else if ((*lista)->next != NULL)
		ft_lstappend(&((*lista)->next), listb);
	else
		(*lista)->next = listb;
}

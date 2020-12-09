/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:29:05 by zkubli            #+#    #+#             */
/*   Updated: 2020/01/26 16:27:29 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstprepend(t_list **lista, t_list *listb)
{
	t_list *endb;

	if (lista == NULL || listb == NULL)
		return ;
	if (*lista == NULL)
	{
		*lista = listb;
		return ;
	}
	endb = listb;
	while (endb->next != NULL)
		endb = endb->next;
	endb->next = *lista;
	*lista = listb;
}

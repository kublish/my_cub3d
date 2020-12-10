/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:19:40 by zacharyku         #+#    #+#             */
/*   Updated: 2020/10/30 08:42:19 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	*ft_lstpop(t_list **root)
{
	void	*content;
	t_list	*next;

	if (root && *root)
	{
		content = (*root)->content;
		next = (*root)->next;
		free(*root);
		*root = next;
		return (content);
	}
	return (0);
}

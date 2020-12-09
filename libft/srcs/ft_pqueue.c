/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pqueue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 14:18:42 by zkubli            #+#    #+#             */
/*   Updated: 2020/02/10 08:11:35 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

/*
**	this is a min-heap based priority queue
**	It holds nodes with void pointers to store whateve
*/

t_pq		*ft_pqnew(void const *elem, size_t elem_size)
{
	t_pq *newnode;

	newnode = malloc(sizeof(t_pq));
	newnode->count = 0;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
	newnode->content = malloc(elem_size);
	ft_memcpy(newnode->content, elem, elem_size);
	newnode->content_size = elem_size;
	return (newnode);
}

/*
** swaps 'a' and 'b' return the node with
** data from 'a'
** which is at location 'b'
** and has count of 'b'
*/

static t_pq	*ft_pqswap(t_pq *a, t_pq *b)
{
	void	*temp;
	size_t	temp_size;

	temp = a->content;
	temp_size = a->content_size;
	a->content = b->content;
	a->content_size = b->content_size;
	b->content = temp;
	b->content_size = temp_size;
	return (b);
}

void		ft_pqpush(t_pq **r, int (*f)(void *a, void *b), t_pq *n)
{
	if (*r == NULL)
	{
		*r = n;
		return ;
	}
	(*r)->count++;
	if (!((*r)->left) || !((*r)->right))
	{
		if ((*r)->left)
			(*r)->right = n;
		else
			(*r)->left = n;
		n->parent = (*r);
		while (n->parent && f(n->parent->content, n->content) > 0)
			n = ft_pqswap(n, n->parent);
	}
	else if ((*r)->right->count < (*r)->left->count)
		ft_pqpush(&((*r)->right), f, n);
	else
		ft_pqpush(&((*r)->left), f, n);
}

/*
** remove a node from the queue
*/

void		*ft_pqpop(t_pq **r, int (*f)(void *a, void *b))
{
	void *content;

	(*r)->count--;
	if ((*r)->left || (*r)->right)
		if (!((*r)->left) || ((*r)->right &&
					f((*r)->right->content, (*r)->left->content) < 0))
			return (ft_pqpop(&(ft_pqswap((*r)->right, *r)->right), f));
		else
			return (ft_pqpop(&(ft_pqswap((*r)->left, (*r))->left), f));
	else
	{
		content = (*r)->content;
		free(*r);
		*r = NULL;
		return (content);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:54:17 by zkubli            #+#    #+#             */
/*   Updated: 2020/02/09 16:11:59 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_list	*find_mid(t_list *root)
{
	t_list *fast;
	t_list *slow;

	fast = root;
	slow = root;
	while (fast)
	{
		fast = fast->next;
		if (fast)
			fast = fast->next;
		if (fast)
			slow = slow->next;
	}
	return (slow);
}

static int		nodecmp(t_list *a, t_list *b, int (*f) (void *, void *))
{
	if (a)
		if (b)
			return (f(a->content, b->content));
		else
			return (-1);
	else if (b)
		return (1);
	return (0);
}

static t_list	*my_pop_nofree(t_list **a)
{
	t_list *temp;

	temp = *a;
	(*a) = (*a)->next;
	return (temp);
}

static t_list	*merge(t_list *a, t_list *b, int (*f) (void *, void *))
{
	t_list	*re_val;
	t_list	*tmp;
	int		cmp;

	if (a == NULL)
		return (b);
	if (b == NULL)
		return (a);
	if (nodecmp(a, b, f) < 0)
		re_val = my_pop_nofree(&a);
	else
		re_val = my_pop_nofree(&b);
	tmp = re_val;
	while (a || b)
	{
		cmp = nodecmp(a, b, f);
		tmp->next = (cmp < 0) ? a : b;
		if (cmp < 0)
			a = a->next;
		else
			b = b->next;
		tmp = tmp->next;
	}
	return (re_val);
}

void			ft_lstsort(t_list **root, int (*f) (void *, void *))
{
	t_list *a;
	t_list *b;
	t_list *tmp;

	if (root == NULL || *root == NULL || (*root)->next == NULL)
		return ;
	a = *root;
	tmp = find_mid(a);
	b = tmp->next;
	tmp->next = NULL;
	ft_lstsort(&a, f);
	ft_lstsort(&b, f);
	*root = merge(a, b, f);
}

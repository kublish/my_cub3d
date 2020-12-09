/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 10:50:37 by zacharyku         #+#    #+#             */
/*   Updated: 2020/12/01 10:34:44 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "cub3d.h"

/*
** Map reader may be weak to terminating characters in the map
** beacuse of the trailing \0. This may be removed by utilizing
** content_size and ft_memcpy instead of ft_strcpy
*/

void	free_and_child(void **ptr)
{
	free(*ptr);
	free(ptr);
}

int		check_line(long start, int increment, long end_input)
{
	char	*p;
	char	*end;
	char	prev;
	int		ec;

	p = (char *)start;
	end = (char *)end_input;
	ec = 0;
	prev = ' ';
	while (p < end && ec == 0)
	{
		if (prev == ' ')
			ec = 13 * (*p != ' ' && *p != '1' && *p);
		else if (is_player(prev) || prev == '2' || prev == '0')
			ec = 13 * (*p == ' ' || *p == '\0');
		if (*p && *p < '0' && *p > '2' && !is_player(*p) && *p != ' ')
			ec = 10;
		prev = *p;
		p += increment;
	}
	return (ec);
}

int		check_map(t_data *d)
{
	long	i;
	int		ec;
	
	i = -1;
	ec = 0;
	while (++i < d->map.tablelen && ec <= 1)
		if (is_player(d->map.table[i]))
			ec++;
		else if (d->map.table[i] != ' ' && d->map.table[i] != '\0' &&
				d->map.table[i] > '2' && d->map.table[i] < '0')
			return (9);
	if (ec != 1)
		return ((ec > 1) ? 12 : 11);
	i = (long)d->map.table;
	while (i < (long)(d->map.table + d->map.tablelen))
		if ((ec = check_line(i, 1,
				(long)(i + d->map.rowlen))))
			return (ec);
		else
			i += (long)(d->map.rowlen);
	i = (long)(d->map.table) - 1;
	while (++i < (long)(d->map.table + d->map.rowlen))
		if ((ec = check_line(i, d->map.rowlen, i + d->map.rowlen)))
			return (ec);
	return (0);
}

int		read_map(char *line, int fd, t_data *data)
{
	t_list	*root;
	int		strlen;
	int		i;

	root = ft_lstnew(&line, sizeof(char *));
	data->map.tablelen = 1;
	data->map.rowlen = ft_strlen(line);
	while (gnl(fd, &line) != 1)
	{
		ft_lstadd(&root, ft_lstnew(&line, sizeof(char *)));
		if ((strlen = ft_strlen(line)) > data->map.rowlen)
			data->map.rowlen = strlen;
		data->map.tablelen++;
	}
	data->map.tablelen *= data->map.rowlen;
	data->map.table = malloc(sizeof(char) * data->map.tablelen);
	ft_bzero(data->map.table, data->map.tablelen);
	i = 0;
	while (root)
	{
		ft_strcpy(data->map.table + data->map.tablelen - data->map.rowlen
				* ++i, *(char **)(root->content));
		free_and_child(ft_lstpop(&root));
	}
	return (check_map(data));
}


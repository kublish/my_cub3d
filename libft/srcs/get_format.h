/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:18:25 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:25:21 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_FORMAT_H
# define GET_FORMAT_H
# include <stdarg.h>

typedef struct		s_format_data
{
	unsigned int	plus : 1;
	unsigned int	minus : 1;
	unsigned int	space : 1;
	unsigned int	zero : 1;
	unsigned int	h : 1;
	unsigned int	hh : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	pound : 1;
	unsigned int	big_l : 1;
	unsigned int	caps : 1;
	int				width;
	int				prec;
	int				base;
	unsigned int	isneg : 1;
	int				len;
}					t_format_data;

void				get_format(char **input, t_format_data *fd, va_list ap);
#endif

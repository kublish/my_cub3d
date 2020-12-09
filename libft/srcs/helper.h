/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:30:15 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:15:12 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
# include "get_format.h"

typedef unsigned long long t_ull;

int			is_spec(char c);
int			is_flag(char c);
int			my_atoi(char **s);
int			numlen(t_ull num, int base, int prec);
t_ull		read_arg(va_list ap, t_format_data *fd);

#endif

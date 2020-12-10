/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:48:07 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 16:26:15 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H
# include "get_format.h"

typedef unsigned long long t_ull;

int buffer(const char *to_add, int d);
int loop_char(char c, int n);
int	my_putstr(const char *str, int prec);
int	my_putnbr_base(t_ull num, int prec, t_format_data *fd);
int	put_digit(int i, int caps);
#endif

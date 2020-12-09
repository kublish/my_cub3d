/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 00:49:23 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 15:49:49 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_MATH_H
# define STRING_MATH_H
# define MAX_DIG 512
# include "get_format.h"

typedef union				u_floatcast
{
	double					d;
	struct
	{
		unsigned long long	mantissa : 52;
		unsigned long long	exponent : 11;
		unsigned long long	sign : 1;
	}						s_parts;
}							t_floatcast;

typedef union				u_longdcast
{
	long double				d;
	struct
	{
		unsigned long long	mantissa : 64;
		unsigned long long	exponent : 15;
		unsigned long long	sign : 1;
	}						s_parts;
}							t_longdcast;

void						a_half(char *data);
void						a_double(char *data);
void						a_round(char *data, int prec);

#endif

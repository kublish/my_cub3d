/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:38:21 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/21 14:24:05 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_math.h"

void	a_half(char *data)
{
	int i;
	int carry;

	carry = 0;
	i = -1;
	while (data[++i] || carry)
	{
		if (i >= MAX_DIG)
			break ;
		if (data[i] == '.')
			continue ;
		if (data[i] && (data[i] - '0') % 2 == 1)
			carry += 2;
		data[i] = (data[i] ? (data[i] - '0') / 2 : 0) + '0';
		data[i] += 5 * (carry & 1);
		carry /= 2;
	}
}

void	a_double(char *data)
{
	int i;
	int newdig;
	int carry;

	i = 0;
	while (data[i] && i < MAX_DIG)
		i++;
	newdig = (*data >= '5');
	carry = 0;
	while (--i >= 0)
	{
		if (data[i] == '.')
		{
			data[i + newdig] = '.';
			continue ;
		}
		data[i + newdig] = data[i] + (data[i] - '0') + carry;
		if ((carry = (data[i + newdig] > '9')))
			data[i + newdig] -= 10;
	}
	if (newdig)
		data[0] = '1';
}

void	a_round(char *data, int prec)
{
	int i;

	i = 0;
	while (data[i] && data[i] != '.')
		++i;
	i += prec;
	if (data[i + 1] > '5' || (data[i + 1] == '5'))
	{
		while (data[i] == '9' || data[i] == '.')
			if (data[i] == '.')
				i--;
			else
				data[i--] = '0';
		data[i] += 1;
	}
}

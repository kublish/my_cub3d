/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 21:54:11 by zkubli            #+#    #+#             */
/*   Updated: 2020/02/08 21:55:20 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_digitcount(int n)
{
	int re_val;

	re_val = 1;
	while ((n /= 10) > 0)
		re_val++;
	return (re_val);
}
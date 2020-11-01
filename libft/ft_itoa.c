/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:50:00 by zkubli            #+#    #+#             */
/*   Updated: 2019/09/26 11:03:52 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int		n2;
	int		i;
	int		isneg;
	char	*re_val;

	isneg = (n < 0);
	n *= (1 - (2 * isneg));
	n2 = n;
	i = -1;
	while (++i == 0 || n2 != 0)
		n2 /= 10;
	i += 1 + (isneg);
	if (!(re_val = (char *)(malloc(i * sizeof(char)))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(re_val, "-2147483648"));
	if (isneg)
		re_val[0] = '-';
	re_val[--i] = '\0';
	while (--i >= isneg)
	{
		re_val[i] = n % 10 + '0';
		n /= 10;
	}
	return (re_val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpolyjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 06:58:15 by zkubli            #+#    #+#             */
/*   Updated: 2020/03/11 10:52:29 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>



#include <stdio.h>


static int	ft_doublestrlen(char **str)
{
	int t;

//	printf("test");	
	t = 0;
	while(*str)
		t += ft_strlen(*(str++));
//	printf("num:%d\n", t);
	return (t);
}

/*
** I'm sorry god, Norme made me do it!
*/



char		*ft_strpolyjoin(int n, ...)
{
	va_list	ap;
	char	**data;
	char	*output;
	int		i;

	va_start(ap, n);
	data = malloc(sizeof(char *) * (n + 1));
	i = 0;
	while (i < n)
		data[i++] = va_arg(ap, char *);
	data[i] = NULL;
//	for (int j = 0; data[j]; j++)
//		printf("%s\n", data[j]);
//	printf("this");
//	ft_doublestrlen(data);
//	printf("that");
	output = malloc(sizeof(char) * (ft_doublestrlen(data) + 1));
	i = 0;
	n = 0;
	while (data[n])
	{
		while (data[n][0])
			output[i++] = *((data[n])++);
		n++;
	}
	output[i] = '\0';
	va_end(ap);
	free(data);
	return (output);
}

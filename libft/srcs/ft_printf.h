/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:20:52 by zkubli            #+#    #+#             */
/*   Updated: 2019/11/22 16:18:07 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_specf
{
	char		c;
	int			(*f)(char **, va_list);
}				t_specf;

int				ft_printf(char *input, ...);
int				ft_printf_c(char **input, va_list ap);
int				ft_printf_s(char **input, va_list ap);
int				ft_printf_p(char **input, va_list ap);
int				ft_printf_d(char **input, va_list ap);
int				ft_printf_o(char **input, va_list ap);
int				ft_printf_u(char **input, va_list ap);
int				ft_printf_f(char **input, va_list ap);
int				ft_printf_x_nocap(char **input, va_list ap);
int				ft_printf_x_cap(char **input, va_list ap);
int				ft_printf_percent(char **input, va_list ap);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdestroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkubli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 20:32:27 by zkubli            #+#    #+#             */
/*   Updated: 2019/12/20 18:31:12 by zkubli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/*
** Should remove the 2nd line?
** Or maybe add a line for setting to zero
*/

void	ft_vdestroy(t_vector *kill_me)
{
	free(kill_me->data);
	free(kill_me);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zacharykubli <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:16:49 by zacharyku         #+#    #+#             */
/*   Updated: 2020/10/30 20:33:41 by zacharyku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int     is_player(const char a)
{
	return  (a == 'N' || a == 'S' || a == 'E' || a == 'W');
}

/*
**  perp_distance provides the point perpendicular to the end of vec, at
**  distance relative to size of vec. positive ratio is to the right.
*/

void    perp_vec(t_dpoint *vec, double ratio, t_dpoint *re_vec)
{
    re_vec->x = vec->y * ratio + vec->x;
    re_vec->y = -vec->x * ratio + vec->y;
}

void    ray_cast_init(t_data *d, t_dpoint *ray, t_ray_data *)
{
    map_pos->x = (int)d->cam.player.x;
    map_pos->y = (int)d->cam.player.y;
    if (ray)
}

int     ray_cast(t_dpoint *ray_dir, t_data *d, t_dpoint *hit, int *is_NS)
{

    int     hit_found;

    ft_memcpy(hit, )
}
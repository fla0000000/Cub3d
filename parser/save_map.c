/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 03:49:17 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/09 16:19:01 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_parsering(t_data *game, char *buff)
{
    (void)game;
    if(!buff)
        exit(-1);
    write(1, buff, strlen(buff));
    
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:53 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/07 17:28:47 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_map(t_mapp *map, char *map_cub, int ac)
{
    ft_check_input(ac, map_cub);
    ft_check_size(map,map_cub);
}

int main(int ac, char **av)
{
    t_mapp map;
    t_cub3d cub3d;
        
    cub3d.mlx =  mlx_init();
    map.map = NULL;
    map.readmap = NULL;
    parser_map(&map,av[1], ac);
    cub3d.mlx_win = mlx_new_window(cub3d.mlx, 500, 500, "CUB3D" );
    mlx_loop(cub3d.mlx);

    
}
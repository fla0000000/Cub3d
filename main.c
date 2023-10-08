/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:53 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/08 21:44:53 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_map(t_cub3d *cub3d, char *map_cub, int ac)
{
    int fd;
    (void)ac;
    fd = open(map_cub, O_RDONLY);
    if(fd == -1)
       exit(write(2, "Error\nMap not found\n", 20));
    // ft_check_input(ac, map_cub);
    ft_check_size(cub3d, fd);
}

int main(int ac, char **av)
{
    t_cub3d cub3d;
        
    ft_check_input(ac, av[1]);
    cub3d.mlx =  mlx_init();
    parser_map(&cub3d,av[1], ac);
    cub3d.mlx_win = mlx_new_window(cub3d.mlx, 500, 500, "CUB3D" );
    mlx_loop(cub3d.mlx);
    
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:53 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/09 03:53:43 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_map(t_data *data, char *map_cub)
{
    int fd;
    char *buff;

    buff = 0;
    fd = open(map_cub, O_RDONLY);
    if(fd == -1)
       exit(write(2, "Error\nMap not found\n", 20));
    buff = get_next_line(fd);
    while(buff)
    {
        ft_parsering(data, buff);
        free(buff);
        buff = get_next_line(fd);
    }
}

void init_mlx(t_cub3d *cub3d)
{
     cub3d->mlx =  mlx_init();
    cub3d->mlx_win = mlx_new_window(cub3d->mlx, 500, 500, "CUB3D" );
    mlx_loop(cub3d->mlx);
}

int main(int ac, char **av)
{
    t_data game;
    t_cub3d cub3d;
        
    ft_bzero(&game, sizeof(t_data));
    ft_check_input(ac, av[1]);
    parser_map(&game, av[1]);
    init_mlx(&cub3d);
     parser_map(av[1]);
    
}


// | KEY           | Action        |
// | ------------- |:-------------:|
// | `ESC`         | exit game     |
// | `A`           | move left     |
// | `D`           | move right    |
// | `W`           | move forward  |
// | `S`           | move backward |
// | `→`           | turn right    |
// | `←`           | turn left     |
// | `M`           | hide/display map|
// | `O`           | open/close door|
// | `P`           | open/close secret door|
// | `option`      | change weapon |
// | `F10`         | sound on/off |
//code
// | `1`            | wall          |
// | `0`            | floor         |
// | `2`            | sprite #1     |
// | `3`            | sprite #2     |
// | `N`/`E`/`W`/`S`| player initial position + orientation|
// | `A`            | ammo          |
//*
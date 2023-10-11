/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:53 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/11 16:46:44 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_map(t_data *game, char *map_cub)
{
    int fd;
    char *buff;

    (void)game;
    buff = 0;
    fd = open(map_cub, O_RDONLY);
    if(fd == -1)
       exit(write(2, "Error\nMap not found\n", 20));
    buff = get_next_line(fd);
    while(buff)
    {
        ft_parsering(game, buff);
        free(buff);
        buff = get_next_line(fd);
    }
    free(buff);
     printf("no:%s\n", game->value.no);
    printf("so:%s\n", game->value.so);
    printf("we:%s\n", game->value.we);
    printf("ea:%s\n", game->value.ea);
     printf("game->value.c.b:%d\n", game->value.c.b);
     printf("game->value.c.g:%d\n", game->value.c.g);
    printf("game->value.c.r:%d\n", game->value.c.r);
    printf("game->value.f.b:%d\n", game->value.f.b);
    printf("game->value.f.g:%d\n", game->value.f.g);
    printf("game->value.f.r:%d\n", game->value.f.r);
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
    ft_check_text(&game);
    init_mlx(&cub3d);
    //  parser_map(av[1]);
    
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:59:53 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/12 00:14:29 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_map(t_data *game, char *map_cub)
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

void initfc(t_data *game)
{
    game->value.c.b = -1;
    game->value.c.r = -1;
    game->value.c.g = -1;
    game->value.f.b = -1;
    game->value.f.r = -1;
    game->value.f.g = -1;
    
}

int main(int ac, char **av)
{
    t_data game;
    t_cub3d cub3d;
        
    ft_bzero(&game, sizeof(t_data));
    ft_check_input(ac, av[1]);
    initfc(&game);
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
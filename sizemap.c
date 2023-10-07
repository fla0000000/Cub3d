/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:09:04 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/07 17:33:27 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_mat(char **mat)
{
	int	y;
	int	x;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			write(1, &mat[y][x], 1);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}

void    ft_check_size(t_mapp *map, char *map_cub)
{
    char *g_n_l;
    int fd;
    
    fd = open(map_cub, O_RDONLY);
    if(fd == -1)
       exit(write(2, "Error\nMap not found\n", 20));
    g_n_l = get_next_line(fd);
    if(!g_n_l)
        exit(write(2, "Error\nMap not found\n", 20));
    map->y = 0;
    map->x = strlen(g_n_l) - 1;
    while(g_n_l)
    {
       free(g_n_l);
       g_n_l = get_next_line(fd);
       map->y++; 
    }
    free(g_n_l);
    printf("%d\n", map->y);
    close(fd);
}

void	ft_check_input( int ac, char *av)
{
	int	len;

	if (ac != 2)
		exit(write(2, "Error: Invalid input\n", 21));
	len = ft_strlen(av);
	if (!(av[len - 1] == 'b' && av[len - 2] == 'u' && av[len - 3]
			== 'c' && av[len - 4] == '.'))
		exit(write(2, "Error: Map isnt in .cub format\n", 24));
}
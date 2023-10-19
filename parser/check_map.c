/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:41:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/19 20:09:05 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//controlla se i valori che non sono 1 sono contornati da spazi
void	check_fraime(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map_x[++y])
	{
		x = -1;
		while (game->map_x[y][++x])
		{
			if (ft_strchr("0NSWED", game->map_x[y][x]))
			{
				if (game->map_x[y - 1][x] == ' ' || game->map_x[y + 1][x] == ' '
					|| game->map_x[y + 1][x + 1] == ' ' || game->map_x[y - 1][x
					- 1] == ' ' || game->map_x[y + 1][x - 1] == ' '
					|| game->map_x[y - 1][x + 1] == ' ')
					exit(write(2, "Error: 0NSWED\n", 15));
			}
		}
	}
}
//E TRASFORMA gli spazi in K
//checka la presenza dei soli caratterri "1 0 N S W E 32 \n" nella mappa
void	check(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map_x[++y])
	{
		x = -1;
		while (game->map_x[y][++x])
		{
			if (ft_strchr("10NSWED", game->map_x[y][x]))
			{
				continue ;
				// printf("\nmap%c\n", game->map_x[y][x]);
			}
			if(game->map_x[y][x] == '\n')
			{
				game->map_x[y][x] = 'K';
				// printf("\nmap/n%c\n", game->map_x[y][x]);
			}
			if(game->map_x[y][x] == ' ')
			{
				game->map_x[y][x] = 'K';
				// printf("\nma p%c\n", game->map_x[y][x]);
			}
			if(!ft_strchr("10NSWEDK \n", game->map_x[y][x]))
					exit(write(2, "Error:invalid caratter\n", 22));
		}
		printf("\nmap%s\n", game->map_x[y]);
	}
}

int check_map(t_data *game)
{
	check_fraime(game);
	check(game);
	return 0;
}

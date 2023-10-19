/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:41:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/19 17:43:45 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			// printf("\nmap%c\n", game->map_x[y][x]);
			if (ft_strchr("10NSWED ", game->map_x[y][x]) ||  game->map_x[y][x] == '\n')
				continue ;
			else
					exit(write(2, "Error:invalid caratter\n", 22));
		}
	}
}

int check_map(t_data *game)
{
	check_fraime(game);
	check(game);
	return 0;
}

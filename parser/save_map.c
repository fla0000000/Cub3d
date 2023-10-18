/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:41:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/18 15:46:46 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void ft_check_map(t_data *game)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;	
// 	if(game->map_x[y][x]) 
// }

// calcola la x più lunga della mappa
void	long_len_x(t_data *game)
{
	int	i;
	int	y;

	i = 0;
	// game->map = (game->map, sizeof(char) * game->y + 1);
	while (game->map_x[i])
	{
		y = 0;
		printf("\n%d:%s",i,  game->map_x[i]);
		while (game->map_x[i][y])
		{
			if (ft_isdigit(game->map_x[i][y]))
			{
						// printf("\ni:%s", game->map[i]);
				if (ft_strlen(game->map_x[i]) > game->x)
				{
					game->x = ft_strlen(game->map_x[i]);
					// 	printf("\nx:%zu\n", game->x);
					break ;
				}
					break ;
			}
			y++;
		}
		i++;
	}
}

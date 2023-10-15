/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 18:41:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/15 22:20:27 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_mapp(t_data *game, char *buff)
{
	int i;

	i = -1;
	(void)game;
	while (buff[++i])
		{
			if (ft_strchr("NSWE", buff[i]))
			{
				printf("1buff=%s\n", buff);
				return ;
			}
            if (ft_strchr("CF", buff[i]))
			{
				printf("1buffcf=%s\n", buff);
				return ;
            }
			if(!ft_strchr(INVISI_CHAR, buff[i]))
			if (!ft_isdigit(buff[i]))
                {
                    
					printf("2buff=%s\n", buff);
				printf("\nbuffi:%c\n", buff[i]);
                break ;
                }
		}
}

void	parser_map(t_data *game, char *path)
{
	char *buff;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(write(2, "Error\nMap not found\n", 20));
	buff = get_next_line(fd);
	while (buff)
	{
		ft_mapp(game, buff);
		free(buff);
		buff = get_next_line(fd);
	}
}
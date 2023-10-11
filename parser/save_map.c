/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 03:49:17 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/11 17:58:11 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_texture(t_data *game, char *buff)
{
	char	*text;

	text = ft_substr(buff, 0, 2);
	// printf("%s\n", text);
	if (ft_strncmp("NO", text, 2) == 0)
	{
		if(game->value.no)
            exit(write(2, "Error: Double Texture\n", 22));
		game->value.no = ft_substr(buff, 3, ft_strlen(buff) - 3);
		// printf("no:%s\n", game->value.no);
	}
	else if (ft_strncmp("SO", text, 2)== 0)
	{
		if(game->value.so)
            exit(write(2, "Error: Double Texture\n", 22));
		game->value.so = ft_substr(buff, 3, ft_strlen(buff) - 3);
		// printf("so:%s\n", game->value.so);
	}
	else if (ft_strncmp("WE", text, 2)== 0)
	{
		if(game->value.we)
            exit(write(2, "Error: Double Texture\n", 22));
		game->value.we = ft_substr(buff, 3, ft_strlen(buff) - 3);
		// printf("we:%s\n", game->value.we);
	}
	else if (ft_strncmp("EA", text, 2) == 0)
	{
		if(game->value.ea)
            exit(write(2, "Error: Double Texture\n", 22));
		game->value.ea = ft_substr(buff, 3, ft_strlen(buff) - 3);
		// printf("ea:%s", game->value.ea);
	}
}
void	ft_ciel_floor2(t_data *game, char *text, char *substr, int i)
{
	while (ft_isdigit(substr[i]))
		i++;
	while (!ft_isdigit(substr[i]))
		i++;
	if (ft_atoi(substr + i) > 255 || ft_atoi(substr + i) < 0)
		exit(write(2, "Error: Invalid Texture\n", 23));
	if (ft_strncmp("C", text, 1) == 0)
		game->value.c.g = ft_atoi(substr + i);
	else
		game->value.f.g = ft_atoi(substr + i);
	while (ft_isdigit(substr[i]))
		i++;
	while (!ft_isdigit(substr[i]))
		i++;
	if (ft_atoi(substr + i) > 255 || ft_atoi(substr + i) < 0)
		exit(write(2, "Error: Invalid Texture\n", 20));
	if (ft_strncmp("C", text, 1) == 0)
		{
		if(game->value.c.r > 0)
			exit(write(2, "Error: Invalid C.R\n", 20));
		game->value.c.r = ft_atoi(substr + i);
		}
	else
		{
			if(game->value.f.r > 0)
					exit(write(2, "Error: Invalid F.R\n", 23));
		game->value.f.r = ft_atoi(substr + i);
		}
	free(text);
	free(substr);
}

void	ft_ciel_floor(t_data *game, char *buff)
{
	char	*text;
	char	*substr;
	int		i;

	i = 0;
	substr = NULL;
	text = ft_substr(buff, 0, 1);
	substr = ft_substr(buff, 2, ft_strlen(buff) - 2);
	while (!ft_isdigit(substr[i]))
		i++;
	if (ft_atoi(substr + i) > 255 || ft_atoi(substr + i) < 0)
		exit(write(2, "Error: Invalid Texture\n", 23));
	if (ft_strncmp("C", text, 1) == 0)
		{
			if(game->value.c.b > 0)
				exit(write(2, "Error: Double Texture\n", 23));
		game->value.c.b = ft_atoi(substr + i);
		}
	else
		{
		if(game->value.f.b > 0)
				exit(write(2, "Error: Double Texture\n", 23));
		game->value.f.b = ft_atoi(substr + i);
		}
	ft_ciel_floor2(game,text,substr,i);
	
}

void ft_check_text(t_data *game)
{
	if(game->value.ea == NULL)
			exit(write(2, "Error: Invalid check_ea\n", 25));
	if(game->value.no == NULL )
			exit(write(2, "Error: Invalid check_no\n", 25));
	if(game->value.we == NULL )
			exit(write(2, "Error: Invalid check_we\n", 25));
	if(game->value.so == NULL )
			exit(write(2, "Error: Invalid check_so\n", 25));
}




int	ft_parsering(t_data *game, char *buff)
{
	(void)game;
	if (!buff)
		exit(-1);
	if (ft_strchr("NSWE", buff[0]))
	{
		ft_texture(game, buff);
	}
	if (ft_strchr("CF", buff[0]))
	{
		// printf("%c", buff[0]);
		ft_ciel_floor(game, buff);
	}
	// write(1, buff, strlen(buff));
	// printf("%lu\n", strlen(buff));
	return (0);
}
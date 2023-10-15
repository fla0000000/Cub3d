/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 03:49:17 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/15 23:20:55 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_texture(t_data *game, char *buff)
{
	int	i;

	// char	*text;
	i = -1;
	// text = ft_substr(buff, 0, 2);
	while (buff[++i])
	{
		if (ft_strchr("N", buff[i]))
		{
			if (ft_strchr("O", buff[i + 1]))
			{
				// printf("n:%s\n", buff);
				// printf("n:%c\n", buff[i]);
				if (game->value.no)
					exit(write(2, "Error: Double TextureNO\n", 23));
				game->value.no = ft_substr(buff, i + 2, ft_strlen(buff) - i + 2);
				return ;
				// printf("no:%s\n", game->value.no);
			}
		}
		if (ft_strchr("S", buff[i]))
		{
			if (ft_strchr("O", buff[i + 1]))
			{
				// printf("s:%s\n", buff);
				// printf("s:%c\n", buff[i]);
				if (game->value.so)
					exit(write(2, "Error: Double TextureS0\n", 23));
				game->value.so = ft_substr(buff, i + 2, ft_strlen(buff) - i + 2);
				return ;
				// printf("so:%s\n", game->value.so);
			}
		}
		if (ft_strchr("W", buff[i]))
		{
			if (ft_strchr("E", buff[i + 1]))
			{
				// printf("w:%s\n", buff);
				// printf("w:%c\n", buff[i]);
				if (game->value.we)
					exit(write(2, "Error: Double TextureWE\n", 23));
				game->value.we = ft_substr(buff, i + 2, ft_strlen(buff) - i + 2);
				return ;
				printf("we:%s\n", game->value.we);
			}
		}
		if (ft_strchr("E", buff[i]))
		{
			if (ft_strchr("A", buff[i + 1]))
			{
				// printf("e:%s\n", buff);
				// printf("e:%c\n", buff[i]);
				if (game->value.ea)
					exit(write(2, "Error: Double TextureEA\n", 23));
				game->value.ea = ft_substr(buff, i + 2, ft_strlen(buff) - i + 2);
				return ;
				// printf("ea:%s", game->value.ea);
			}
		}
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
		if (game->value.c.r > 0)
			exit(write(2, "Error: Invalid C.R\n", 20));
		game->value.c.r = ft_atoi(substr + i);
	}
	else
	{
		if (game->value.f.r > 0)
			exit(write(2, "Error: Invalid F.R\n", 23));
		game->value.f.r = ft_atoi(substr + i);
	}
	free(text);
	free(substr);
}


void	ft_ciel_floor(t_data *game, char *buff, int j)
{
	char	*text;
	char	*substr;
	int		i;

	i = 0;
	substr = NULL;
	text = ft_substr(buff, j, 1);
	substr = ft_substr(buff, j + 1, ft_strlen(buff) - j +1);
	if (check_virg(substr) != 2)
		exit(write(2, "Error: Invalid Texture\n", 23));
	while (!ft_isdigit(substr[i]))
		i++;
	if (ft_atoi(substr + i) > 255 || ft_atoi(substr + i) < 0)
		exit(write(2, "Error: Invalid Texture\n", 23));
	if (ft_strncmp("C", text, 1) == 0)
	{
		if (game->value.c.b > 0)
			exit(write(2, "Error: Double Texture\n", 23));
		game->value.c.b = ft_atoi(substr + i);
	}
	else
	{
		if (game->value.f.b > 0)
			exit(write(2, "Error: Double Texture\n", 23));
		game->value.f.b = ft_atoi(substr + i);
	}
	ft_ciel_floor2(game, text, substr, i);
}

int	ft_parser_tex(t_data *game, char *buff, int *i)
{
	int j;

	j = -1;
	if (!buff)
		exit(-1);
	while (buff[++j])
	{
		if (ft_strchr("NSWE", buff[j]))
		{
			ft_texture(game, buff);
			return (0);
		}
		if (ft_strchr("CF", buff[j]))
		{
			// printf("%c", buff[0]);
			ft_ciel_floor(game, buff, j);
			return (0);
		}
	}
	game->y++;
	if(!game->map_x)
			game->map_x = realloc(game->map_x, sizeof(char *) * game->y + 1);
	else
	game->map_x = realloc(game->map_x, sizeof(char *) * game->y);
	game->map_x[(*i)] = ft_strdup(buff);
		game->map_x[++(*i)] = 0;
	// write(1, buff, strlen(buff));
	// printf("%lu\n", strlen(buff));
	return (0);
}
// salvataggio delle texture e dei valori di CF
// game->x= len della mappa
void parser_y(t_data *game, char *map_cub)
{
    int fd;
    char *buff;
	int i;

	i = -1;
    buff = 0;
    fd = open(map_cub, O_RDONLY);
   if(fd == -1)
       exit(write(2, "Error\nMap not found\n", 20));
    buff = get_next_line(fd);
    while(buff)
    {
        ft_parser_tex(game, buff, &i);
        free(buff);
        buff = get_next_line(fd);
    }
	// game->map_x = realloc(game->map_x, sizeof(char *) * 1);
	// game->map_x[++i] = 0;
    free(buff);
	ft_check_text(game);
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
    printf("\ny:%d\n" , game->y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:00:25 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/18 21:00:08 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <time.h>

#	define INVISI_CHAR "\t\v\r\f "

typedef struct				s_rgb
{
	int						r;
	int						g;
	int						b;
}							t_rgb;

typedef struct s_value
{
	char			*no;
	char			*we;
	char			*so;
	char			*ea;
    struct				s_rgb f;
    struct				s_rgb c;
    
}					t_value;

typedef struct s_data
{
	size_t				x;
	int				y;
    char **map_x;
	struct s_value	value;
	char	**map;
}					t_data;

typedef struct s_cub3d
{
	void			*mlx;
	void			*mlx_win;
	struct s_data	env;
}					t_cub3d;

void ft_print_mat(char **mat);
//parser
void parser_cub(t_data *game, char *map_cub);
void	long_len_x(t_data *game);
void	ft_mapp(t_data *game);


//check_parser
void ft_check_input(t_data *game, int ac, char *av);
int	check_virg(char *substr);
void	ft_check_text(t_data *game);

#endif
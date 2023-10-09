/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:00:25 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/09 02:37:41 by flaviobiond      ###   ########.fr       */
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
//# include "libft/libft.h"
# include "getnextline/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <time.h>

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

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;

typedef struct s_data
{
	// int				x;
	// int				y;
	// struct s_value	value;
	struct s_map	*map;
}					t_data;

typedef struct s_cub3d
{
	void			*mlx;
	void			*mlx_win;
	struct s_data	env;
}					t_cub3d;

//check_map
void				ft_check_input(int ac, char *av);

#endif
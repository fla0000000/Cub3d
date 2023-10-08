/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:00:25 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/10/08 22:54:58 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include <stdint.h>
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

typedef struct s_value
{
	char	*no;
	char	*we;
	char	*so;
	char	*ea;
	int		f[3];
	int		c[3];
}	    t_value;

typedef struct s_maps
{
	char			**readmap;
	char			**map;
	int				x;
	int				y;
    struct s_value  value;
}					t_mapp;

typedef struct s_cub3d
{
	void			*mlx;
	void			*mlx_win;
	struct s_maps	mapp;
}					t_cub3d;

//check_map
void				ft_check_size(t_cub3d *cub3d, int fd);
void				ft_check_input(int ac, char *av);

#endif
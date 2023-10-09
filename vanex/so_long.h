/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpalacio <vpalacio@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:16:07 by vpalacio          #+#    #+#             */
/*   Updated: 2023/05/30 11:26:11 by vpalacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"

# define W 13
# define A 0
# define ESC 53
# define S 1
# define D 2

typedef struct s_game
{
	void			*image;
	void			*mlx;
	void			*mlx_window;
	int				x;
	int				y;
}					t_game;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
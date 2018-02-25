/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:13:53 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/25 17:17:20 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHORT_MINILIBX_H
# define SHORT_MINILIBX_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

typedef struct		s_short_minilibx
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	void			*img; // todo remove
	void			(*init)(); // self
	int				(*key)(); // int keycode, void *param
	int				(*mouse)(); // int button, x, y, void *param
	int				(*expose)(); // void *param
	int				(*loop)(); // void *param
}					t_short_minilibx;

typedef struct		s_short_minilibx_image
{
	int				width;
	int				height;
	int				xposition;
	int				yposition;
	void			*img;
	int				*raw;
}					t_short_minilibx_image;

void				short_minilibx_init(void *const self, char *const title, int image_count, ...);
void				short_minilibx_deinit(void);

void				*short_minilibx_data(void *const self);

#endif

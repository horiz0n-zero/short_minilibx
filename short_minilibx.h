/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:13:53 by afeuerst          #+#    #+#             */
/*   Updated: 2018/03/02 13:11:06 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHORT_MINILIBX_H
# define SHORT_MINILIBX_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

# define PIXEL(r, g, b) (int)(b | (g << 8) | (r << 16))

typedef struct		s_short_minilibx
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	void			*image;
	void			(*init)();
	int				(*key)();
	int				(*mouse)();
	int				(*expose)();
	int				(*loop)();
	char			*error;
}					t_short_minilibx;

typedef struct		s_short_minilibx_image
{
	int				width;
	int				height;
	int				xposition;
	int				yposition;
	void			*img;
	int				**raw;
	void			*next;
	char			*file;
}					t_short_minilibx_image;

void				short_minilibx_init(void *const self, char *const title,
		int image_count, ...);
void				short_minilibx_deinit(void);

void				*short_minilibx_data(void *const self);

#endif

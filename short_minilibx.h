/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:13:53 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/24 17:00:15 by afeuerst         ###   ########.fr       */
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
}					t_short_minilibx;

void				short_minilibx_init(void *const self, char *const title, int image_count, ...);
void				short_minilibx_deinit(void);

void				*short_minilibx_data(void *const self);

#endif

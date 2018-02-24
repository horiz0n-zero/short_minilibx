/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:22:09 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/24 16:56:09 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

void									short_minilibx_init(void *const self,
		char *const title, int image_count, ...)
{
	va_list								args;
	t_short_minilibx *const				ptr = self;

	va_start(args, image_count);
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, title);
	mlx_clear_window(ptr->mlx, ptr->win);
	va_end(args);
	mlx_loop(ptr->mlx);
}

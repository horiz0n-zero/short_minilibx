/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:22:09 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/25 17:17:44 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

static inline void						short_minilibx_images(t_short_minilibx *const self,
		int image_count, va_list *const args)
{
	t_short_minilibx_image				*ptr;
	int									buffy;

	while (image_count--)
	{
		ptr = va_arg(*args, void*);
		ptr->img = mlx_new_image(self->mlx, ptr->width, ptr->height);
		ptr->raw = (void*)mlx_get_data_addr(ptr->img, &buffy, &buffy, &buffy);
		mlx_put_image_to_window(self->mlx, self->win, ptr->img, ptr->xposition, ptr->yposition);
		self->img = ptr;
	}
}

void									short_minilibx_init(void *const self,
		char *const title, int image_count, ...)
{
	va_list								args;
	t_short_minilibx *const				ptr = self;

	va_start(args, image_count);
	short_minilibx_data(self);
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, ptr->width, ptr->height, title);
	mlx_clear_window(ptr->mlx, ptr->win);
	short_minilibx_images(ptr, image_count, &args);
	if (ptr->init)
		ptr->init(self);
	if (ptr->key)
		mlx_key_hook(ptr->win, ptr->key, self);
	if (ptr->mouse)
		mlx_mouse_hook(ptr->win, ptr->mouse, self);
	if (ptr->expose)
		mlx_expose_hook(ptr->win, ptr->expose, self);
	if (ptr->loop)
		mlx_loop_hook(ptr->mlx, ptr->loop, self);
	va_end(args);
	mlx_loop(ptr->mlx);
}

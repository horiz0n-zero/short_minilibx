/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:22:09 by afeuerst          #+#    #+#             */
/*   Updated: 2018/03/02 13:15:10 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

static inline void						short_minilibx_raw(
		t_short_minilibx_image *const img)
{
	int									**array;
	int									*raw;
	int									i;

	i = 0;
	raw = (void*)img->raw;
	array = malloc(sizeof(int*) * img->height);
	img->raw = array;
	while (i++ < img->height)
	{
		*array++ = raw;
		raw += img->width;
	}
}

static inline void						images_ptr_fill(
		t_short_minilibx_image *const ptr, t_short_minilibx *const self)
{
	if (ptr->file)
		ptr->img = mlx_xpm_file_to_image(self->mlx, ptr->file,
				&ptr->width, &ptr->height);
	else
		ptr->img = mlx_new_image(self->mlx, ptr->width, ptr->height);
}

static inline void						short_minilibx_images(
		t_short_minilibx *const self, int image_count, va_list *const args)
{
	t_short_minilibx_image				*ptr;
	t_short_minilibx_image				*last;
	int									buffy[3];

	last = NULL;
	while (image_count--)
	{
		ptr = va_arg(*args, void*);
		images_ptr_fill(ptr, self);
		ptr->raw = (void*)mlx_get_data_addr(ptr->img,
				buffy, buffy + 1, buffy + 2);
		short_minilibx_raw(ptr);
		if (!last)
		{
			last = ptr;
			self->image = ptr;
		}
		else
		{
			last->next = ptr;
			last = ptr;
		}
	}
}

static inline void						short_minilibx_images_add(
		t_short_minilibx *const self)
{
	t_short_minilibx_image				*ptr;

	ptr = self->image;
	while (ptr)
	{
		mlx_put_image_to_window(self->mlx, self->win, ptr->img,
				ptr->xposition, ptr->yposition);
		ptr = ptr->next;
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
	if (!ptr->mlx | !ptr->win)
		return ((void)(ptr->error = "mlx_init failed.\n"));
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
	short_minilibx_images_add(ptr);
	mlx_loop(ptr->mlx);
}

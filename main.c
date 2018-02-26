/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:29:20 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/26 15:00:15 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

typedef struct				s_used
{
	t_short_minilibx		self;
	t_short_minilibx_image	image;
	t_short_minilibx_image	button;
	t_short_minilibx_image	icone;
}							t_used;

#include <string.h>
#include <stdio.h>

static inline void			fill_target(int *raw, int count, const int color)
{
	while (count--)
	{
		*raw++ = color;
	}
}

static void					func_init(t_used *const used)
{
	fill_target(used->image.raw, used->image.width * used->image.height, PIXEL(255, 255, 232));
	fill_target(used->button.raw, used->button.width * used->button.height, PIXEL(0, 23, 142));
	fill_target(used->icone.raw, used->icone.width * used->icone.height, PIXEL(0, 23, 0));
}

static struct s_used		g_used =
{
	{
		NULL, NULL, 1920, 1080, NULL,
		func_init, NULL, NULL, NULL, NULL,
		NULL
	},
	{
		1920, 1080, 0, 0, NULL, NULL, NULL
	},
	{
		500, 500, 1920 / 2 - 250, 1080 / 2 - 250, NULL, NULL, NULL
	},
	{
		200, 200, 1920 - 250, 1080 - 250, NULL, NULL, NULL
	}
};

int							main(int argc, char **argv)
{
	short_minilibx_init(&g_used, "hello short minilibx", 3, &g_used.image, &g_used.button, &g_used.icone);
	return (0);
}

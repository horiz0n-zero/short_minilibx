/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:29:20 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/25 17:18:31 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

typedef struct				s_used
{
	t_short_minilibx		self;
	t_short_minilibx_image	image;
}							t_used;

#include <string.h>
#include <stdio.h>

static void					func_init(t_used *const used)
{
	memset(used->image.raw, 0xFF00FF00, sizeof(int) * used->image.width * used->image.height);
	printf("%p %p\n", used->image.img, used->image.raw);
	mlx_put_image_to_window(used->self.mlx, used->self.win, used->self.img, 0, 0);
}

static struct s_used		g_used =
{
	{
		NULL, NULL, 1920, 1080,
		func_init, NULL, NULL, NULL, NULL
	},
	{
		1920, 1080, 0, 0, NULL, NULL
	}
};

int							main(int argc, char **argv)
{
	short_minilibx_init(&g_used, "hello short minilibx", 1, &g_used.image);
	return (0);
}

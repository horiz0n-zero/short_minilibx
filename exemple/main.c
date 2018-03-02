/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:34:18 by afeuerst          #+#    #+#             */
/*   Updated: 2018/03/02 13:03:42 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

/*
 * -> on MAC OS clang main.c ../short_minilibx.a -framework OpenGL -framework AppKit -I .. ../minilibx_macos/libmlx.a
 */

typedef struct				s_exemple
{
	t_short_minilibx		self;
	t_short_minilibx_image	background;
	t_short_minilibx_image	gray;
	t_short_minilibx_image	icone;
}						t_exemple;

static void					fill_with_color(int *ptr, const int color, size_t len)
{
	while (len--)
		*ptr++ = color;
}

static void					exemple_init(struct s_exemple *exemple)
{
	fill_with_color(*exemple->background.raw, PIXEL(237, 182, 23), exemple->background.width * exemple->background.height);
	fill_with_color(*exemple->gray.raw, PIXEL(170, 170, 170), exemple->gray.width * exemple->gray.height);
}

static int					exemple_key(int keycode, struct s_exemple *exemple)
{
	if (keycode == 53) // mac os esc
	{
		short_minilibx_deinit();
		exit(0);
	}
	return (0);
}

static struct s_exemple		exemple =
{
	.self =
	{
		NULL, NULL, 1920, 1080, NULL,
		exemple_init, exemple_key, NULL, NULL, NULL, NULL 
	},
	.background =
	{
		1920, 1080, 0, 0, NULL, NULL, NULL, NULL
	},
	.gray =
	{
		1920 / 2, 1080 / 2, 1920 / 4, 1080 / 4, NULL, NULL, NULL, NULL
	},
	.icone =
	{
		0, 0, 0, 0, NULL, NULL, NULL, "./bande.xpm"
	}
};

int					main(void)
{
	/* for zposition, from background to foreground or z+1 -> */
	short_minilibx_init(&exemple, "Hello Short Minilibx", 3, &exemple.background, &exemple.gray, &exemple.icone);
	return (0);
}

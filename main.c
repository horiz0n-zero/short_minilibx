/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:29:20 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/24 16:57:25 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./short_minilibx.h"

static t_short_minilibx		teste =
{
	NULL, NULL, 1920, 1080
};

int		main(int argc, char **argv)
{
	short_minilibx_init(&teste, "hello", 0);
	return (0);
}

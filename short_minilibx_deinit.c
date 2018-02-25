/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx_deinit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:26:35 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/25 16:42:02 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

void							short_minilibx_deinit(void)
{
	t_short_minilibx *const		ptr = short_minilibx_data(NULL);

	mlx_destroy_window(ptr->mlx, ptr->win);
}

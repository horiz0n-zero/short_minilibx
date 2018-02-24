/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_minilibx_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:28:03 by afeuerst          #+#    #+#             */
/*   Updated: 2018/02/24 15:44:47 by afeuerst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "short_minilibx.h"

void					*short_minilibx_data(void *const self)
{
	static void			*pointer;

	if (self)
	{
		pointer = self;
	}
	return (pointer);
}

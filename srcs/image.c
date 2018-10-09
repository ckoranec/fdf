/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:12:24 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:30:29 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_image(t_object *w)
{
	w->img = mlx_new_image(w->mlx, WIDTH, HIEGHT);
	w->ptr = mlx_get_data_addr(w->img,
		&w->bpp, &w->size_line, &w->endian);
	w->bpp /= 8;
	w->rx = 0.0;
	w->ry = 0.0;
	w->rz = 0.0;
}

void	img_pixel_put(t_object *w, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HIEGHT)
		*(int *)(w->ptr + (int)((y * WIDTH + x) * w->bpp)) = color;
}

void	clear_image(t_object *w)
{
	ft_bzero(w->ptr, WIDTH * HIEGHT * w->bpp);
}

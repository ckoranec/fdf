/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:11:53 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:30:07 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bresenham_x(t_object *object, t_point a, t_point b)
{
	int m_new;
	int slope_error_new;
	int x;
	int y;
	int neg;

	neg = 0;
	m_new = 2 * (b.y - a.y);
	slope_error_new = m_new - (b.x - a.x);
	if (a.y > b.y && (neg = 1))
		m_new = 2 * -(a.y - b.y);
	x = a.x;
	y = a.y;
	while (x <= b.x)
	{
		if (a.colored || b.colored)
			img_pixel_put(object, x, y, 0xffffff);
		else
			img_pixel_put(object, x, y, 0x2eff05);
		slope_error_new += m_new + (x++ * 0);
		if (slope_error_new >= 0 && !neg)
			slope_error_new -= 2 * (b.x - a.x) + (y++ * 0);
		else if (slope_error_new <= 0 && neg)
			slope_error_new += 2 * (b.x - a.x) + (y-- * 0);
	}
}

void	bresenham_y(t_object *object, t_point a, t_point b)
{
	int m_new;
	int slope_error_new;
	int x;
	int y;
	int neg;

	neg = 0;
	m_new = 2 * (b.x - a.x);
	slope_error_new = m_new - (b.y - a.y);
	if (a.x > b.x && (neg = 1))
		m_new = 2 * -(a.x - b.x);
	x = a.x;
	y = a.y;
	while (y <= b.y)
	{
		if (a.colored || b.colored)
			img_pixel_put(object, x, y, 0xffffff);
		else
			img_pixel_put(object, x, y, 0x2eff05);
		slope_error_new += m_new + (y++ * 0);
		if (slope_error_new >= 0 && !neg)
			slope_error_new -= 2 * (b.y - a.y) + (x++ * 0);
		else if (slope_error_new <= 0 && neg)
			slope_error_new += 2 * (b.y - a.y) + (x-- * 0);
	}
}

void	bresenham_xfilter(t_object *object, t_point a, t_point b)
{
	if (fabsf(b.x - a.x) < fabsf(b.y - a.y))
	{
		if (b.y < a.y)
			bresenham_yfilter(object, b, a);
		else
			bresenham_yfilter(object, a, b);
		return ;
	}
	if (b.x < a.x)
		bresenham_xfilter(object, b, a);
	else
		bresenham_x(object, a, b);
}

void	bresenham_yfilter(t_object *object, t_point a, t_point b)
{
	if (fabsf(b.y - a.y) < fabsf(b.x - a.x))
	{
		if (b.x < a.x)
			bresenham_xfilter(object, b, a);
		else
			bresenham_xfilter(object, a, b);
		return ;
	}
	if (b.y < a.y)
		bresenham_yfilter(object, b, a);
	else
		bresenham_y(object, a, b);
}

void	draw(t_object *object)
{
	int i;
	int j;

	j = 0;
	while (j < object->rows)
	{
		i = 0;
		while (i < object->cols)
		{
			if (i + 1 < object->cols)
				bresenham_xfilter(object, object->arr[j][i],
					object->arr[j][i + 1]);
			if (j + 1 < object->rows)
				bresenham_yfilter(object, object->arr[j][i],
					object->arr[j + 1][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(object->mlx, object->window, object->img, 0, 0);
}

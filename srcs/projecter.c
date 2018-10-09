/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projecter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:13:37 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:31:23 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_scale(t_object *object)
{
	t_point	*h;
	int		max;

	h = object->point_lst;
	if (object->rows > object->cols)
		max = object->rows;
	else
		max = object->cols;
	while (h)
	{
		h->x *= (800 / max);
		h->y *= (800 / max);
		h->z *= 28;
		h = h->next;
	}
}

void	adjust_roto(t_object *object)
{
	mult_matrix(object, object->matx);
	mult_matrix(object, object->maty);
	mult_matrix(object, object->matz);
	object->rx = 0;
	object->ry = 0;
	object->rz = 0;
}

void	project(t_object *object)
{
	t_point *h;

	h = object->point_lst;
	while (h)
	{
		if (!(h->z))
			h->z = 1;
		h->x = ((100 * (h->x - WIDTH / 2)) /
			(100 + h->z)) + WIDTH / 2;
		h->y = ((100 * (h->y - HIEGHT / 2)) /
			(100 + h->z)) + HIEGHT / 2;
		h = h->next;
	}
}

void	move(t_object *object, int xadj, int yadj)
{
	t_point *h;

	h = object->point_lst;
	while (h)
	{
		h->x += xadj;
		h->y += yadj;
		h = h->next;
	}
}

void	center(t_object *object)
{
	t_point	*h;
	int		xlow;
	int		xhigh;
	int		ylow;
	int		yhigh;

	h = object->point_lst;
	xlow = h->x;
	xhigh = h->x;
	ylow = h->y;
	yhigh = h->y;
	while (h)
	{
		if (h->x > xhigh)
			xhigh = h->x;
		if (h->x < xlow)
			xlow = h->x;
		if (h->y > yhigh)
			yhigh = h->y;
		if (h->y < ylow)
			ylow = h->y;
		h = h->next;
	}
	move(object, (WIDTH / 2) - ((xlow + xhigh) / 2),
		(HIEGHT / 2) - ((ylow + yhigh) / 2));
}

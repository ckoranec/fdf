/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:12:39 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:30:39 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		update_array(t_object *object)
{
	t_point *h;
	int		i;
	int		j;

	h = object->point_lst;
	i = 0;
	while (i < object->rows)
	{
		j = 0;
		while (j < object->cols)
		{
			object->arr[i][j] = *h;
			j++;
			h = h->next;
		}
		i++;
	}
}

void		init_array(t_object *object)
{
	t_point **arr;
	t_point *h;
	int		i;
	int		j;

	h = object->point_lst;
	if (!(arr = malloc(sizeof(t_point *) * object->rows + 1)))
		ft_close();
	i = 0;
	while (i < object->rows)
	{
		if (!(arr[i] = malloc(sizeof(t_point) * object->cols + 1)))
			ft_close();
		j = 0;
		while (j < object->cols)
		{
			arr[i][j] = *h;
			j++;
			h = h->next;
		}
		i++;
	}
	object->arr = arr;
}

t_point		*init_point(int x, int y, int z, int color)
{
	t_point *point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->z = z;
	point->next = NULL;
	point->color = color;
	if (z > 0)
		point->colored = 1;
	else
		point->colored = 0;
	return (point);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:13:18 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:31:12 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	identity_matrix(float mat[4][4])
{
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 0;
	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 0;
	mat[1][3] = 0;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

void	mult_matrix(t_object *object, float mat[4][4])
{
	float	x;
	float	y;
	float	z;
	t_point *h;

	h = object->point_lst;
	while (h)
	{
		x = h->x;
		y = h->y;
		z = h->z;
		h->x = x * mat[0][0] + y * mat[1][0] + z * mat[2][0] + mat[3][0];
		h->y = x * mat[0][1] + y * mat[1][1] + z * mat[2][1] + mat[3][1];
		h->z = x * mat[0][2] + y * mat[1][2] + z * mat[2][2] + mat[3][2];
		h = h->next;
	}
}

void	set_mat(t_object *object)
{
	identity_matrix(object->matx);
	identity_matrix(object->maty);
	identity_matrix(object->matz);
	object->matx[1][1] = cos(object->rx);
	object->matx[1][2] = sin(object->rx);
	object->matx[2][1] = -sin(object->rx);
	object->matx[2][2] = cos(object->rx);
	object->maty[0][0] = cos(object->ry);
	object->maty[0][2] = -sin(object->ry);
	object->maty[2][0] = sin(object->ry);
	object->maty[2][2] = cos(object->ry);
	object->matz[0][0] = cos(object->rz);
	object->matz[0][1] = sin(object->rz);
	object->matz[1][0] = -sin(object->rz);
	object->matz[1][1] = cos(object->rz);
}

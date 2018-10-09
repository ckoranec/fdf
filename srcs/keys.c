/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:12:50 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:30:50 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			key_pressed_hook(int key, t_object *object)
{
	if (key == 124)
		object->ry = 0.033;
	if (key == 123)
		object->ry = -0.033;
	if (key == 126)
		object->rx = 0.033;
	if (key == 125)
		object->rx = -0.033;
	if (key == 53)
		ft_close();
	render(object);
	return (0);
}

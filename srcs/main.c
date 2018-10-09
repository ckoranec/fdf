/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:13:06 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/25 19:16:11 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void		render(t_object *object)
{
	set_mat(object);
	adjust_roto(object);
	center(object);
	update_array(object);
	clear_image(object);
	draw(object);
}

int			main(int ac, char **av)
{
	t_object	object;
	char		*line;

	line = NULL;
	if (ac != 2)
	{
		ft_error();
		return (0);
	}
	if ((object.fd = open(av[1], O_RDONLY)) == -1)
		ft_error();
	read_file(&object, line);
	close(object.fd);
	object.mlx = mlx_init();
	object.window = mlx_new_window(object.mlx,
		WIDTH, HIEGHT, av[1]);
	init_image(&object);
	set_scale(&object);
	mlx_hook(object.window, 2, 0, key_pressed_hook, &object);
	init_array(&object);
	render(&object);
	mlx_loop(object.mlx);
	pause();
	return (0);
}

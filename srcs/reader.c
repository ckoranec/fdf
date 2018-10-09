/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:13:49 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/25 19:21:53 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/libft.h"

void		read_line(t_object *object, char *s)
{
	t_point	*trav;
	t_point	*new_point;
	int		cols;

	cols = 0;
	while (*s)
	{
		if ((ft_isdigit(*s) || *s == '-'))
		{
			trav = object->point_lst;
			new_point = init_point(cols++,
				object->rows, ft_atoi(s), 0);
			while (trav->next)
				trav = trav->next;
			trav->next = new_point;
			while (*(s + 1) == '-' || ft_isalnum(*(s + 1))
				|| *(s + 1) == ',')
				s++;
		}
		s++;
	}
	if (object->cols == 0)
		object->cols = cols;
	else if (object->cols != cols)
		ft_error();
}

void		read_file(t_object *object, char *line)
{
	t_point *head;

	head = init_point(0, 0, 0, 0);
	object->point_lst = head;
	object->rows = -1;
	object->cols = 0;
	while ((get_next_line(object->fd, &line) > 0))
	{
		if (!*line)
			ft_error();
		(object->rows)++;
		read_line(object, line);
		free(line);
	}
	free(line);
	if (!object->point_lst->next)
		ft_error();
	object->point_lst = object->point_lst->next + (object->rows++ * 0);
	free(head);
}

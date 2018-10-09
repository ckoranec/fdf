/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:28:31 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:29:01 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# define WIDTH 1300
# define HIEGHT 1300

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				colored;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct		s_object
{
	void			*img;
	void			*ptr;
	int				bpp;
	int				endian;
	int				size_line;

	int				cols;
	int				rows;
	int				fd;

	int				lines;
	char			**tab;
	void			*mlx;
	void			*window;
	t_point			*point_lst;
	t_point			**arr;
	float			matx[4][4];
	float			maty[4][4];
	float			matz[4][4];
	float			rx;
	float			ry;
	float			rz;
}					t_object;

void				ft_close(void);
void				ft_error(void);
void				ft_usage(void);
void				mult_matrix(t_object *object, float mat[4][4]);
void				identity_matrix(float mat[4][4]);
void				set_mat(t_object *object);
void				bresenham_x(t_object *object, t_point a, t_point b);
void				bresenham_y(t_object *object, t_point a, t_point b);
void				bresenham_xfilter(t_object *object, t_point a, t_point b);
void				bresenham_yfilter(t_object *object, t_point a, t_point b);
void				draw(t_object *object);
int					key_pressed_hook(int key, t_object *object);
void				init_cam(t_object *object);
void				init_array(t_object *object);
t_point				*init_point(int x, int y, int z, int color);
void				update_array(t_object *object);
void				init_image(t_object *w);
void				img_pixel_put(t_object *w, int x, int y, int color);
void				clear_image(t_object *w);
void				set_scale(t_object *object);
void				adjust_roto(t_object *object);
void				project(t_object *object);
void				move(t_object *object, int xadj, int yadj);
void				center(t_object *object);
void				render(t_object *object);
void				read_file(t_object *object, char *line);
void				read_line(t_object *object, char *s);

#endif

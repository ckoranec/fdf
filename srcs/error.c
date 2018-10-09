/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:12:11 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:30:18 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_close(void)
{
	exit(0);
}

void	ft_error(void)
{
	perror("Error ");
	exit(0);
}

void	ft_usage(void)
{
	ft_putendl("Usage : ./fdf <filename>");
	exit(-1);
}

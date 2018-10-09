/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkertgat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 23:56:26 by jkertgat          #+#    #+#             */
/*   Updated: 2018/09/16 16:02:22 by jkertgat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*ptr;

	while ((!(!line) || !(ret = -1)) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr = s[fd];
		if (!(s[fd] = ft_strjoin(s[fd], buf)))
			s[fd] = ft_strdup(buf);
		ft_strdel(&ptr);
	}
	if ((ret == -1 || !ft_strlen(s[fd])) && (!line || (*line = ft_strnew(0))))
		return (ret);
	ptr = ft_strchr(s[fd], '\n');
	if (ptr && !(*ptr = '\0'))
		ptr = ft_strdup(ptr + 1);
	else
		ptr = ft_strnew(0);
	*line = ft_strdup(s[fd]);
	free(s[fd]);
	s[fd] = ptr;
	return (1);
}

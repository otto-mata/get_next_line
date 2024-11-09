/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:24 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 21:24:39 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_read_wrapper(int fd, char **b)
{
	int		i;
	char	*buf;
	char	*tmp;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	i = read(fd, buf, BUFFER_SIZE);
	tmp = ft_strndup(*b, ft_strlen(*b));
	free(*b);
	buf[i] = 0;
	if (i > 0)
		*b = ft_strjoin(tmp, buf);
	else
		*b = ft_strndup(tmp, ft_strlen(tmp));
	free(tmp);
	free(buf);
	return (i);
}

char	*get_next_line(int fd)
{
	ssize_t			idx;
	static t_params	b;
	char			*ret;

	if (b.state == 2)
		return (0);
	if (!b.state)
	{
		b.buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!b.buf)
			return (0);
		b.state = 1;
		b.i = 1;
	}
	idx = ft_index_of(b.buf, '\n');
	while (b.i > 0 && idx < 0)
	{
		b.i = ft_read_wrapper(fd, &b.buf);
		idx = ft_index_of(b.buf, '\n');
	}
	if (b.i == -1
		|| (b.i == 0
			&& (ft_strlen(b.buf) + 1 == b.last_sz
				|| b.state == 1)))
	{
		free(b.buf);
		b.buf = 0;
		b.state = 2;
		return (0);
	}
	if (idx < 0)
		idx = ft_strlen(b.buf);
	ret = ft_roll_left(&b.buf, idx);
	b.last_sz = ft_strlen(ret);
	return (ret);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("file.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	close(fd);
// }

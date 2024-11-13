/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:24 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/13 20:32:05 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_append(char *dst, char const *src)
{
	char	*dup;

	dup = ft_strndup(dst, ft_strlen((const char *)dst));
	free(dst);
	dst = ft_strjoin(dup, src);
	free(dup);
	return (dst);
}

char	*ft_extract_line(t_buffer *buff)
{
	size_t	ix;
	char	*dup;
	char	*dup2;

	ix = (size_t)ft_index_of(buff->s, '\n');
	dup = ft_strndup(buff->s, ft_strlen(buff->s));
	free(buff->s);
	if (ix == ft_strlen(dup) - 1)
	{
		buff->s = ft_calloc(1, sizeof(char));
		return (dup);
	}
	dup2 = ft_strndup(dup, ix);
	buff->s = ft_strndup(dup + ix + 1, ft_strlen(dup) - ix + 1);
	free(dup);
	buff->empty = (buff->s[0] == 0);
	return (dup2);
}

void	ft_populate_tmp(char *tmp)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		tmp[i] = 0;
		i++;
	}
}

char	*ft_return_end_empty_buffer(char **buffer)
{
	char	*dup;
	
	if (*buffer == 0)
		return (0);
	dup = ft_strndup(*buffer, ft_strlen(*buffer));
	free(*buffer);
	*buffer = 0;
	return (dup);
}

char	*get_next_line(int fd)
{
	static t_buffer	buff;
	char			tmp[BUFFER_SIZE + 1];
	ssize_t			rx;

	ft_populate_tmp(tmp);
	rx = read(fd, tmp, BUFFER_SIZE);
	if (rx < 0)
		return (0);
	if (!buff.state)
	{
		buff.state = 1;
		buff.s = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	}
	while (rx)
	{
		buff.s = ft_append(buff.s, tmp);
		if (ft_index_of(buff.s, '\n') > -1)
			return (ft_extract_line(&buff));
		rx = read(fd, tmp, BUFFER_SIZE);
	}
	return (ft_return_end_empty_buffer(&buff.s));
}

// int	main(int ac, char **av)
// {
// 	int		fd;
// 	char	*s;

// 	if (ac < 2)
// 		return ((int)printf("No file provided.\n"));
// 	fd = open(av[1], O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("1. %s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("2. %s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("3. %s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("4. %s", s);
// 	free(s);
// 	/* s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s); */
// 	close(fd);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:24 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/14 14:06:28 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *s, int offset)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	s += offset;
	str = calloc((strlen(s) + 1), sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	free(s - offset);
	return (str);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t s1sz;
	size_t sz; 
	char			*s;
	size_t			i;

	if (!s1)
		return (ft_strdup(s2, 0));
	if (!s2)
		return (ft_strdup(s1, 0));
	s1sz = strlen(s1);
	sz = s1sz + strlen(s2) + 1;
	s = calloc(sz, sizeof(char));
	if (!s)
		return (0);
	i = -1;
	while (++i < s1sz)
		s[i] = s1[i];
	while (i < sz)
	{
		s[i] = s2[i - s1sz];
		i++;
	}
	free(s1);
	free(s2);
	return (s);
}

char *get_next_line(int fd)
{
	char *buffer;
	int sz;
	char *line;
	static char *save;
	
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	sz = read(fd, buffer, BUFFER_SIZE);
	while (sz > 0)
	{
		save = ft_strjoin2(save, buffer);
		for (int i = 0; i < (int)strlen(save); ++i)
		{
			if (save[i] == '\n')
			{
				line = calloc(i + 1, sizeof(char));
				for (int j = 0; j < i + 1; ++j)
					line[j] = save[j];
				save = ft_strdup(save, i + 1);
				return (line);
			}
		}
		buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
		sz = read(fd, buffer, BUFFER_SIZE);
	}

	free(buffer);
	if (save)
	{	
		buffer = ft_strdup(save, 0);
		free(save);
		save = 0;
		return (buffer);
	}
	return (0);
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

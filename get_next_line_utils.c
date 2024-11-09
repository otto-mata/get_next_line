/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:27 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/09 20:29:16 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_index_of(char const *s, char c)
{
	ssize_t	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && i < n + 1)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_roll_left(char **s, size_t i)
{
	char			*ret;
	size_t const	sz = ft_strlen(*s);
	char			*s2;

	ret = ft_strndup(*s, i);
	s2 = ft_strndup(&(s[0][i + 1]), sz);
	if (!s2)
		s2 = 0;
	free(*s);
	*s = s2;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t const	s1sz = ft_strlen(s1);
	size_t const	sz = s1sz + ft_strlen(s2) + 1;
	char			*s;
	size_t			i;

	s = malloc(sz * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (i < s1sz)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < sz)
	{
		s[i] = s2[i - s1sz];
		i++;
	}
	s[i] = 0;
	return (s);
}

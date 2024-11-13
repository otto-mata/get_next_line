/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:58:27 by tblochet          #+#    #+#             */
/*   Updated: 2024/11/13 14:41:52 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *mem, size_t sz)
{
	while (sz--)
		*(unsigned char *)mem++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t sz)
{
	void	*ptr;
	size_t	msz;

	msz = nmemb * sz;
	if (nmemb == 0 || sz == 0)
	{
		nmemb = 1;
		sz = 1;
	}
	if ((int)nmemb < 0 || (int)sz < 0)
		return (0);
	ptr = malloc(msz);
	if (ptr)
		ft_bzero(ptr, msz);
	return (ptr);
}

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
	str = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i] && i < n + 1)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*ft_roll_left(char **s, size_t i)
{
	char			*ret;
	size_t const	sz = ft_strlen(*s);
	char			*s2;

	ret = ft_strndup(*s, i);
	s2 = ft_strndup(&(*s[i + 1]), sz);
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

	s = ft_calloc(sz, sizeof(char));
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
	return (s);
}
